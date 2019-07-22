#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <include/MvCameraControl.h>

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <QTimer>

MV_CC_DEVICE_INFO_LIST m_stDevList;
MV_CC_DEVICE_INFO* m_Device= NULL;

#define MAX_IMAGE_DATA_SIZE   (40*1024*1024)

Mat rgb_image;

unsigned int frameNumber;


Mat BytestoMat(uint8_t* bytes,int width,int height)
{
    Mat image = Mat(height, width, CV_8UC1, bytes);
    return image;
}

static void* WorkThread(void* pUser)
{
    int nRet = MV_OK;
    Mat raw_image;

    MV_FRAME_OUT_INFO_EX stImageInfo;
    memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));
    unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * MAX_IMAGE_DATA_SIZE);
    unsigned int nDataSize = MAX_IMAGE_DATA_SIZE;

    while(1)
    {
//        nRet = MV_CC_SetCommandValue(pUser, "TriggerSoftware");
//        if(MV_OK != nRet)
//        {
//            printf("failed in TriggerSoftware[%x]\n", nRet);
//        }
        nRet = MV_CC_GetOneFrameTimeout(pUser, pData, nDataSize, &stImageInfo, 1000);
        if (nRet == MV_OK)
        {
            printf("GetOneFrame, Width[%d], Height[%d], nFrameNum[%d]\n",
                stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);

            raw_image = BytestoMat(pData, stImageInfo.nWidth, stImageInfo.nHeight);

            frameNumber = stImageInfo.nFrameNum;

            if(raw_image.data)
            {
                cvtColor(raw_image, rgb_image, CV_BayerRG2BGR);
                qDebug()<<stImageInfo.nFrameNum << "Width: "<< stImageInfo.nWidth << "Height: "<< stImageInfo.nHeight;

            }

//            if(g_bExit)
//            {
//                break;
//            }
        }
        else
        {
            printf("Get One Frame failed![%x]\n", nRet);
        }
    }

    if (pData)
    {
        free(pData);
        pData = NULL;
    }

    return 0;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    m_hDevHandle = NULL;
    ui->setupUi(this);

    int tab_width = (ui->tabWidget->width()/2);
    int height = 20;
    ui->tabWidget->setStyleSheet("QTabBar::tab { height:" + QString::number(height)
                                 + "px; width: " + QString::number(tab_width) + "px;}");
    ui->tabWidget->setCurrentIndex(0);
   times = new QTimer(this);
   times->setInterval(800);
   connect(times, SIGNAL(timeout()), this, SLOT(dis()));
}

MainWindow::~MainWindow()
{
    delete ui;
    if(m_hDevHandle)
    {
        MV_CC_DestroyHandle(m_hDevHandle);
        m_hDevHandle = NULL;
    }
}

int MainWindow::Enumdevices(MV_CC_DEVICE_INFO_LIST* pstDevList)
{
    int temp = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, pstDevList);
    if( MV_OK != temp)
    {
        return -1;
    }
    return 0;
}

int MainWindow::connectCamera(string id)
{
    int temp = Enumdevices(&m_stDevList);
    if(temp != 0)
    {
        return -1;
    }
    if(m_stDevList.nDeviceNum == 0)
    {
        return 2;
    }
    for(unsigned int i = 0; i < m_stDevList.nDeviceNum; i++)
    {
        MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
        if(NULL == pDeviceInfo)
        {
            continue;
        }
        if( id == (char *)pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName || id == (char*)pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber)
        {
            m_Device = m_stDevList.pDeviceInfo[i];
            PrintDeviceInfo(pDeviceInfo);
            break;
        }
        else
        {
            continue;
        }
    }
    if(m_Device == NULL)
    {
        return 3;
    }
    temp = MV_CC_CreateHandle(&m_hDevHandle, m_Device);
    if(temp != 0)
    {
        return -1;
    }
    temp = MV_CC_OpenDevice(m_hDevHandle);
    if(temp != 0)
    {
        MV_CC_DestroyHandle(m_hDevHandle);
        m_hDevHandle = NULL;
        return -1;
    }
    else
    {
        setTriggerMode(1);
        return 0;
    }
    if(m_Device->nTLayerType == MV_GIGE_DEVICE)
    {
        printf("Gige Camera");
    }
}

/****************************************************
 * Function   : Start Camera
 * Return Type: None
 * **************************************************/
int MainWindow::startCamera()
{

    MV_CC_SetEnumValue(m_hDevHandle, "LineSelector", 1);        //select line for strobe

    MV_CC_SetEnumValue(m_hDevHandle, "LineMode", 8);            //select line mode as strobe

    //MV_CC_SetEnumValue(m_hDevHandle, "LineSelector", 0);        //select line for Trigger

    //MV_CC_SetEnumValue(m_hDevHandle, "LineMode", 2);            //select line mode as Trigger

    //Trigger External
    trigger_mode();

    //Strobe Enable
     MV_CC_SetBoolValue(m_hDevHandle, "StrobeEnable", true);
   //Line Inverter
     MV_CC_SetBoolValue(m_hDevHandle, "LineInverter", false);
     int temp = MV_CC_StartGrabbing(m_hDevHandle);

    if(temp!=0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int MainWindow::softTrigger()
{
    int temp= MV_CC_SetCommandValue(m_hDevHandle, "TriggerSoftware");
    if(temp != 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

int MainWindow::ReadBuffer(Mat &image)
{
    unsigned int nRecvBufSize = 0;
    MVCC_INTVALUE stParam;
    memset(&stParam, 0, sizeof(MVCC_INTVALUE));
    int temp = MV_CC_GetIntValue(m_hDevHandle, "PayloadSize", &stParam);
    if(temp != 0)
    {
        return -1;
    }
    nRecvBufSize = stParam.nCurValue;
    m_pBufForDriver = (unsigned char *)malloc(nRecvBufSize);
    MV_FRAME_OUT_INFO_EX stImageInfo = {0};
    int tempValue = MV_CC_GetOneFrameTimeout(m_hDevHandle, m_pBufForDriver, nRecvBufSize, &stImageInfo, 700);
    if(tempValue != 0)
    {
        return -1;
    }
    m_nBufSizeForSaveImage = stImageInfo.nWidth * stImageInfo.nHeight * 3 + 2048;
    m_pBufForSaveImage = (unsigned char*)malloc(m_nBufSizeForSaveImage);

    bool isMono;
    switch(stImageInfo.enPixelType)
    {
        case PixelType_Gvsp_Mono8:
        case PixelType_Gvsp_Mono10:
        case PixelType_Gvsp_Mono10_Packed:
        case PixelType_Gvsp_Mono12:
        case PixelType_Gvsp_Mono12_Packed:
            isMono = true;
            break;
        default:
            isMono=false;
            break;
    }

    if(isMono)
    {
        image = Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC1, m_pBufForDriver);
    }

    else
    {
        MV_CC_PIXEL_CONVERT_PARAM stConvertParam = {0};
        memset(&stConvertParam, 0, sizeof(MV_CC_PIXEL_CONVERT_PARAM));
        stConvertParam.nWidth = stImageInfo.nWidth;
        stConvertParam.nHeight = stImageInfo.nHeight;
        stConvertParam.pSrcData = m_pBufForDriver;
        stConvertParam.nSrcDataLen = stImageInfo.nFrameLen;
        stConvertParam.enSrcPixelType = stImageInfo.enPixelType;
        stConvertParam.enDstPixelType = PixelType_Gvsp_RGB8_Packed;
        stConvertParam.pDstBuffer = m_pBufForSaveImage;
        stConvertParam.nDstBufferSize = m_nBufSizeForSaveImage;
        MV_CC_ConvertPixelType(m_hDevHandle, &stConvertParam);
        image = Mat(stImageInfo.nHeight, stImageInfo.nWidth, CV_8UC3, m_pBufForSaveImage);
    }
    return 0;
}

int MainWindow::setExposureTime(float ExposureTimeNum)
{
    int temp  = MV_CC_SetFloatValue(m_hDevHandle, "ExposureTime", ExposureTimeNum);
    if(temp != 0)
    {
        return -1;
    }
    return 0;
}

void MainWindow::dis()
{
//    qDebug("Image Called!");
    QImage img = QImage((const unsigned char*)(rgb_image.data), rgb_image.cols, rgb_image.rows, QImage::Format_RGB888);

    img = img.scaled(ui->labelImage->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ui->labelImage->setPixmap(QPixmap::fromImage(img));


    ui->label_FrameNum->setText(QString::number(frameNumber));
}

bool MainWindow::PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo)
{
    if (NULL == pstMVDevInfo)
    {
        printf("%s\n" , "The Pointer of pstMVDevInfoList is NULL!");
        return false;
    }
    if (pstMVDevInfo->nTLayerType == MV_GIGE_DEVICE)
    {
        // ŽòÓ¡µ±Ç°Ïà»úipºÍÓÃ»§×Ô¶šÒåÃû×Ö
        // print current ip and user defined name
        printf("%s %x\n" , "nCurrentIp:" , pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp);                   //µ±Ç°IP
        printf("%s %s\n\n" , "chUserDefinedName:" , pstMVDevInfo->SpecialInfo.stGigEInfo.chUserDefinedName);     //ÓÃ»§¶šÒåÃû
    }
    else if (pstMVDevInfo->nTLayerType == MV_USB_DEVICE)
    {
        printf("UserDefinedName:%s\n\n", pstMVDevInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName);
    }
    else
    {
        printf("Not support.\n");
    }
    return true;
}

int MainWindow::setTriggerMode(unsigned int TriggerModeNum)
{
    qDebug("In Trigger Mode\n");
    int temp = MV_CC_SetEnumValue(m_hDevHandle, "TriggerMode", TriggerModeNum);
    if(temp != 0)
    {
        return -1;
    }
    return 0;
}

/****************************************************
 * Function   : Camera Connection Logic here
 * Return Type: None
 * **************************************************/

void MainWindow::on_pushButton_CameraConnect_clicked()
{
    int temp = MV_OK;

    temp = Enumdevices(&m_stDevList);
    if(temp != 0)
    {
        qDebug("Failed to Fetch");
    }
    else
    {
        qDebug("Success in Fetching the details");
    }

   temp = connectCamera("sup1");

   qDebug()<<"Return value of connect camera" << temp;


//   temp =  MV_CC_SetEnumValue(m_hDevHandle, "TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
//   qDebug()<<"Trigger Source "<< temp;
   temp = startCamera();
   if(temp != 0)
   {
       qDebug("Camera not Connected");
   }
   else
   {
       qDebug("Camera Connected!");
   }
   pthread_t nThreadID;
   temp = pthread_create(&nThreadID, NULL ,WorkThread , m_hDevHandle);
   if (temp != 0)
   {
       qDebug("thread create failed.ret");
   }

   ui->label->setText("Camera Connected");
    times->start();


}

void MainWindow::capture_image()
{
    int nRet = MV_OK;

    Mat raw_image;


    MV_FRAME_OUT_INFO_EX stImageInfo;
    memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO_EX));

    softTrigger();      //Software Trigger

    unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * MAX_IMAGE_DATA_SIZE);
    unsigned int nDataSize = MAX_IMAGE_DATA_SIZE;

        nRet = MV_CC_GetOneFrameTimeout(m_hDevHandle, pData, nDataSize, &stImageInfo, 1000);
        if (nRet == MV_OK)
        {

//            printf("GetOneFrame, Width[%d], Height[%d], nFrameNum[%d]\t",
//                stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);

            ui->label_FrameNum->setText(QString::number(stImageInfo.nFrameNum));

            raw_image = BytestoMat(pData, stImageInfo.nWidth, stImageInfo.nHeight);
        QImage imbg = QImage((const unsigned char*)pData, stImageInfo.nHeight, stImageInfo.nWidth, QImage::Format_RGB888);

            if(raw_image.data)
            {
//                printf("Data Success! \n");
            }
            cvtColor(raw_image, rgb_image, CV_BayerRG2BGR);
        }
    free(pData);

}

void MainWindow::on_pushButton_SoftwareTrigger_clicked()
{
    capture_image();

    dis();
}

void MainWindow::on_pushButton_Strobe_clicked(bool checked)
{
    if(checked)
    {

        MV_CC_SetBoolValue(m_hDevHandle, "StrobeEnable", checked);     //Enable or Disable Strobe
    }
    else
    {
       MV_CC_SetBoolValue(m_hDevHandle, "StrobeEnable", checked);     //Enable or Disable Strobe
    }
}

void MainWindow::on_pushButton_Inverter_clicked(bool checked)
{
    if(checked)
    {
         MV_CC_SetBoolValue(m_hDevHandle, "LineInverter", checked);    //Line Inverter false
    }
    else
    {
         MV_CC_SetBoolValue(m_hDevHandle, "LineInverter", checked);    //Line Inverter false
    }
}

void MainWindow::on_pushButton_Exposure_clicked()
{
    if(ui->lineEdit_exp->text() != "")
    {
        float temp = ui->lineEdit_exp->text().toFloat();
        MV_CC_SetFloatValue(m_hDevHandle, "ExposureTime", temp);
    }
}

void MainWindow::on_pushButton_Disconnect_clicked()
{
    if(m_hDevHandle)
    {
        MV_CC_DestroyHandle(m_hDevHandle);
        m_hDevHandle = NULL;
    }
    ui->label->setText("Disconnected camera");
}

void MainWindow::on_pushButton_Gain_clicked()
{
    if(ui->lineEdit_Gain->text() != "")
    {
        float temp = ui->lineEdit_Gain->text().toFloat();
        MV_CC_SetFloatValue(m_hDevHandle, "Gain", temp);
    }
}

void MainWindow::trigger_mode()
{
    //Acquisition Mode
    //MV_CC_SetEnumValue(m_hDevHandle, "AcquisitionMode", 2);

    //EXposure Mode
     //MV_CC_SetEnumValue(m_hDevHandle, "ExposureMode", 0);

    //Trigger Selector
    MV_CC_SetEnumValue(m_hDevHandle, "TriggerSelector", 6);

    //Trigger Mode
//    MV_CC_SetEnumValue(m_hDevHandle, "TriggerMode", 1);

    //Trigger Source
    MV_CC_SetEnumValue(m_hDevHandle, "TriggerSource", 0);

    //Trigger Activation
    MV_CC_SetEnumValue(m_hDevHandle, "TriggerActivation", 2);

    //Trigger Delay
    MV_CC_SetFloatValue(m_hDevHandle, "TriggerDelay", 0);

    //Trigger Cache
    MV_CC_SetBoolValue(m_hDevHandle, "TriggerCacheEnable", true);

    //Sensor shutter mode
//    MV_CC_SetBoolValue(m_hDevHandle, "SensorShutterMode", 0);

    //Line Delay
    MV_CC_SetFloatValue(m_hDevHandle, "StrobeLineDelay", 0);
    //Line Duration
    MV_CC_SetFloatValue(m_hDevHandle, "StrobeLineDuration", 0);
    //Line Pre Delay
    MV_CC_SetFloatValue(m_hDevHandle, "StrobeLinePreDelay", 0);

}

void MainWindow::on_comboBox_trigger_mode_currentIndexChanged(const QString &arg1)
{
    qDebug()<<"Trigger Mode: " << arg1;
}

void MainWindow::on_comboBox_trigger_mode_currentIndexChanged(int index)
{
    qDebug()<<"Trigger Mode: " << index;
}

void MainWindow::on_pushButton_SendValues_clicked()
{

}
