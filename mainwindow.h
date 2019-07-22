#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <include/MvCameraControl.h>
#include <include/MvGigEDevice.h>
#include <QTimer>

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

int Enumdevices(MV_CC_DEVICE_INFO_LIST* pstDevList);

int connectCamera(string id);

bool PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo);

int setTriggerMode(unsigned int TriggerModeNum);

int startCamera();

int softTrigger();

int ReadBuffer(Mat &image);

int setExposureTime(float ExposureTimeNum);


private:
    Ui::MainWindow *ui;

    void* m_hDevHandle;

    QTimer * times;

private slots:
    void dis();
    void on_pushButton_CameraConnect_clicked();
    void capture_image();

    void on_pushButton_SoftwareTrigger_clicked();

    void on_pushButton_Strobe_clicked(bool checked);

    void on_pushButton_Inverter_clicked(bool checked);

    void on_pushButton_Exposure_clicked();

    void on_pushButton_Disconnect_clicked();

    void on_pushButton_Gain_clicked();

    void trigger_mode();

    void on_comboBox_trigger_mode_currentIndexChanged(const QString &arg1);

    void on_comboBox_trigger_mode_currentIndexChanged(int index);

    void on_pushButton_SendValues_clicked();

public:
    unsigned char* m_pBufForSaveImage;
    unsigned int m_nBufSizeForSaveImage;

    unsigned char* m_pBufForDriver;
    unsigned int m_nBufSizeForDriver;

};

#endif // MAINWINDOW_H
