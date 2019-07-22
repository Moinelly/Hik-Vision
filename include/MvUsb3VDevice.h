
#ifndef __MV_USB3V_DEVICE_H__
#define __MV_USB3V_DEVICE_H__

#include "MvDeviceBase.h"

namespace MvCamCtrl
{
    class CMvUsb3VDevice : public IMvDevice
    {
    public:

        // ���豸
        virtual int     Open(unsigned int nAccessMode = MV_ACCESS_Exclusive, unsigned short nSwitchoverKey = 0);


        // �ر��豸
        virtual int     Close();


        // �ж��豸��״̬����������falseʱ���ɴ��豸
        virtual bool    IsOpen();


        // ����ץͼ
        virtual int     StartGrabbing();


        // ֹͣץͼ
        virtual int     StopGrabbing();


        // ��ȡ�豸��Ϣ
        virtual int     GetDeviceInfo(MV_CC_DEVICE_INFO&);


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
        virtual int     GetGenICamXML(unsigned char* pData, unsigned int nDataSize, unsigned int* pnDataLen);


        /** @fn     GetOneFrame(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO* pFrameInfo)
         *  @brief  ��ȡһ֡ͼ������
         *  @param  pData           [IN][OUT]   - ����ָ��
                    nDataLen        [IN]        - ���ݳ���
                    pFrameInfo      [OUT]       - �����֡��Ϣ
         *  
         *  @return �ɹ�������MV_OK��ʧ�ܣ����ش�����
         */
        virtual int     GetOneFrame(unsigned char * pData , unsigned int nDataSize, MV_FRAME_OUT_INFO* pFrameInfo);


        // ��ȡGenICamʹ�õĴ���������
        virtual TlProxy     GetTlProxy();


        virtual ~CMvUsb3VDevice( void );


        CMvUsb3VDevice( const MV_CC_DEVICE_INFO* pInfo );

        // ��ʾһ֡ͼ��
        virtual int     Display(void* hWnd);


        // ��ȡ�������͵���Ϣ
        virtual int     GetAllMatchInfo(MV_ALL_MATCH_INFO* pstInfo);

        // ע����Ϣ�쳣�ص�
        virtual int     RegisterExceptionCallBack(void(__stdcall* cbException)(unsigned int nMsgType, void* pUser),
                                                    void* pUser);


        virtual int     SetSingleShot(void(__stdcall* cbSingleShot)(unsigned char* pData , unsigned int nDataLen, 
                                        MV_FRAME_OUT_INFO* pFrameInfo, void* pUser), 
                                        void* pUser);

        // �����豸�ɼ�ģʽ
        virtual int     SetAcquisitionMode(MV_CAM_ACQUISITION_MODE enMode);


        // �豸��������
        virtual int     LocalUpgrade(const void *pFilePathName);

        // ��ȡ��ǰ��������
        virtual int     GetUpgradeProcess(unsigned int* pnProcess);

        virtual int     ReadMemory(void *pBuffer, int64_t nAddress, int64_t nLength);

        virtual int     WriteMemory(const void *pBuffer, int64_t nAddress, int64_t nLength);

        // ����SDK�ڲ�ͼ�񻺴�ڵ��������Χ[1, 30]����ץͼǰ����
        virtual int     SetImageNodeNum(unsigned int nNum);

        // ע��ͼ�����ݻص�
        virtual int     RegisterImageCallBack(void(__stdcall* cbOutput)(unsigned char * pData, MV_FRAME_OUT_INFO* pFrameInfo, void* pUser),
                                                void* pUser);

    private:
        CDevRefs*       m_pRefs;
    };


}

#endif /* __MV_GIGE_DEVICE_H__ */
