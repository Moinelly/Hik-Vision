
#ifndef __MV_TLFACTORY_H__
#define __MV_TLFACTORY_H__

#include "GenApi/Synch.h"
#include "MvInclude.h"
#include "MvDeviceBase.h"

namespace MvCamCtrl
{
    class MV_CAMCTRL_API CTlFactory : public IDeviceFactory
    {
    public:

        /// Retrieve the transport layer factory singleton
        static CTlFactory& GetInstance();


        /// Retrieve all available transport layers
        unsigned int EnumerateTls();


        /** @fn     EnumDevices( unsigned int nTLayerType , MV_CC_DEVICE_INFO_LIST& stDevList )
         *  @brief  ö�������ڣ�ָ���Ĵ���Э���Ӧ�������豸
         *  @param  nTLayerType     [IN]    - ָ���Ĵ���Э��
                    stDevList       [OUT]   - �豸��Ϣ�б�
         *  
         *  @return �ɹ�������MV_OK��ʧ�ܣ����ش�����
         */
        virtual int EnumDevices( unsigned int nTLayerType , MV_CC_DEVICE_INFO_LIST& stDevList );


        /** @fn     CreateDevice( const MV_CC_DEVICE_INFO& device )
         *  @brief  �����豸������
         *  @param  device          [IN]    - �豸��Ϣ����Ҫ�����������Ч���ɣ�
         *  
         *  @return �ɹ��������豸����ʵ����ʧ�ܣ�����NULL
         */
        virtual IMvDevice* CreateDevice( const MV_CC_DEVICE_INFO& device );


        /** @fn     DestroyDevice( IMvDevice* pDevice)
         *  @brief  ����ָ���豸���ڲ���Դ
         *  @param  pDevice         [IN]    - �豸����
         *  
         *  @return �ɹ�������MV_OK��ʧ�ܣ����ش�����
         */
        virtual int DestroyDevice( IMvDevice* );


        /** @fn     IsDeviceAccessible( const MV_CC_DEVICE_INFO& deviceInfo)
         *  @brief  �ж�ָ�����豸�Ƿ���Է���
         *  @param  deviceInfo      [IN]    - ָ�����豸��Ϣ
         *  
         *  @return ���Է��ʣ����� true ��û��Ȩ�޻��豸�ѵ��ߣ����� false 
         *  @note   �ݲ�֧��
         */
        virtual bool IsDeviceAccessible( const MV_CC_DEVICE_INFO& deviceInfo);

        ~CTlFactory( void );

        virtual unsigned int  GetSDKVersion();

    protected:

        static CTlFactory   m_sTLinstance;
        GenApi::CLock       m_cLock;
        CTlRefs*            m_pCreatedTls;

    private:

        CTlFactory( void );
        CTlFactory& operator=( const CTlFactory& );
        CTlFactory( const CTlFactory& );
    };

}

#endif /* __MV_TLFACTORY_H__ */
