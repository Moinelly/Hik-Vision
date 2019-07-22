
#ifndef __MV_DEVICE_BASE_H__
#define __MV_DEVICE_BASE_H__

#include "MvInclude.h"

namespace MvCamCtrl
{

    interface   IMvDevice
    {

        // ���豸
        virtual int     Open(unsigned int nAccessMode = MV_ACCESS_Exclusive, unsigned short nSwitchoverKey = 0)    = 0;


        // �ر��豸
        virtual int     Close()                                 = 0;


        // �ж��豸��״̬����������falseʱ���ɴ��豸
        virtual bool    IsOpen()                                = 0;


        // ����ץͼ
        virtual int     StartGrabbing()                         = 0;


        // ֹͣץͼ
        virtual int     StopGrabbing()                          = 0;


        // ��ȡ�豸��Ϣ
        virtual int     GetDeviceInfo(MV_CC_DEVICE_INFO&)       = 0;


        /** @fn     GetGenICamXML(unsigned char* pData, unsigned int nDataSize, unsigned int* pnDataLen)
         *  @brief  ��ȡ�豸��XML�ļ�
         *  @param  pData           [IN][OUT]   - ������Ļ����ַ
                    nDataSize       [IN]        - �����С
                    pnDataLen       [OUT]       - xml �ļ����ݳ���
         *  
         *  @return �ɹ�������MV_OK��ʧ�ܣ����ش�����
         *  @note   ��pDataΪNULL��nDataSize��ʵ�ʵ�xml�ļ�Сʱ�����������ݣ���pnDataLen����xml�ļ���С��
         *          ��pDataΪ��Ч�����ַ���һ����㹻��ʱ�������������ݣ�����pnDataLen����xml�ļ���С��
         */
        virtual int     GetGenICamXML(unsigned char* pData, unsigned int nDataSize, unsigned int* pnDataLen)        = 0;


        /** @fn     GetOneFrame(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO* pFrameInfo)
         *  @brief  ��ȡһ֡ͼ������
         *  @param  pData           [IN][OUT]   - ����ָ��
                    nDataLen        [IN]        - ���ݳ���
                    pFrameInfo      [OUT]       - �����֡��Ϣ
         *  
         *  @return �ɹ�������MV_OK��ʧ�ܣ����ش�����
         */
        virtual int     GetOneFrame(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO* pFrameInfo)  = 0;


        // ��ȡGenICamʹ�õĴ���������
        virtual TlProxy     GetTlProxy()                                                                            = 0;

        virtual ~IMvDevice( void ){};
    };


    interface   IDeviceFactory
    {

        // ö�������ڣ�ָ���Ĵ���Э���Ӧ�������豸
        virtual int EnumDevices( unsigned int nTLayerType , MV_CC_DEVICE_INFO_LIST& stDevList )     = 0;


        // �����豸������
        virtual IMvDevice* CreateDevice( const MV_CC_DEVICE_INFO& device )                          = 0;


        // ����ָ���豸���ڲ���Դ
        virtual int DestroyDevice( IMvDevice* )                                                     = 0;


        // �ж�ָ�����豸�Ƿ���Է���
        virtual bool IsDeviceAccessible( const MV_CC_DEVICE_INFO& deviceInfo)                       = 0;
    };

    

}

#endif /* __MV_DEVICE_BASE_H__ */
