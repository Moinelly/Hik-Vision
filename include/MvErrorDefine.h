
#ifndef _MV_ERROR_DEFINE_H_
#define _MV_ERROR_DEFINE_H_

//��ȷ�붨��
#define MV_OK                   0x00000000  ///< �ɹ����޴���

//ͨ�ô����붨��:��Χ0x80000000-0x800000FF
#define MV_E_HANDLE             0x80000000  ///< �������Ч�ľ��
#define MV_E_SUPPORT            0x80000001  ///< ��֧�ֵĹ���
#define MV_E_BUFOVER            0x80000002  ///< ��������
#define MV_E_CALLORDER          0x80000003  ///< ��������˳�����
#define MV_E_PARAMETER          0x80000004  ///< ����Ĳ���
#define MV_E_RESOURCE           0x80000006  ///< ��Դ����ʧ��
#define MV_E_NODATA             0x80000007  ///< ������
#define MV_E_PRECONDITION       0x80000008  ///< ǰ���������󣬻����л����ѷ����仯
#define MV_E_VERSION            0x80000009  ///< �汾��ƥ��
#define MV_E_NOENOUGH_BUF       0x8000000A  ///< ������ڴ�ռ䲻��
#define MV_E_ABNORMAL_IMAGE     0x8000000B  ///< �쳣ͼ�񣬿����Ƕ�������ͼ������
#define MV_E_UNKNOW             0x800000FF  ///< δ֪�Ĵ���

// GenICamϵ�д���:��Χ0x80000100-0x800001FF
#define MV_E_GC_GENERIC         0x80000100  ///< ͨ�ô���
#define MV_E_GC_ARGUMENT        0x80000101  ///< �����Ƿ�
#define MV_E_GC_RANGE           0x80000102  ///< ֵ������Χ
#define MV_E_GC_PROPERTY        0x80000103  ///< ����
#define MV_E_GC_RUNTIME         0x80000104  ///< ���л���������
#define MV_E_GC_LOGICAL         0x80000105  ///< �߼�����
#define MV_E_GC_ACCESS          0x80000106  ///< �ڵ������������
#define MV_E_GC_TIMEOUT         0x80000107  ///< ��ʱ
#define MV_E_GC_DYNAMICCAST     0x80000108  ///< ת���쳣
#define MV_E_GC_UNKNOW          0x800001FF  ///< GenICamδ֪����

//GigE_STATUS��Ӧ�Ĵ�����:��Χ0x80000200-0x800002FF
#define MV_E_NOT_IMPLEMENTED    0x80000200  ///< ������豸֧��
#define MV_E_INVALID_ADDRESS    0x80000201  ///< ���ʵ�Ŀ���ַ������
#define MV_E_WRITE_PROTECT      0x80000202  ///< Ŀ���ַ����д
#define MV_E_ACCESS_DENIED      0x80000203  ///< �豸�޷���Ȩ��
#define MV_E_BUSY               0x80000204  ///< �豸æ��������Ͽ�
#define MV_E_PACKET             0x80000205  ///< ��������ݴ���
#define MV_E_NETER              0x80000206  ///< ������ش���
// GigE������еĴ�����
#define MV_E_IP_CONFLICT        0x80000221  ///< �豸IP��ͻ

//USB_STATUS��Ӧ�Ĵ�����:��Χ0x80000300-0x800003FF
#define MV_E_USB_READ           0x80000300      ///< ��usb����
#define MV_E_USB_WRITE          0x80000301      ///< дusb����
#define MV_E_USB_DEVICE         0x80000302      ///< �豸�쳣
#define MV_E_USB_GENICAM        0x80000303      ///< GenICam��ش���
#define MV_E_USB_BANDWIDTH      0x80000304      ///< ������  �ô���������
#define MV_E_USB_UNKNOW         0x800003FF      ///< USBδ֪�Ĵ���

//����ʱ��Ӧ�Ĵ�����:��Χ0x80000400-0x800004FF
#define MV_E_UPG_FILE_MISMATCH     0x80000400 ///< �����̼���ƥ��
#define MV_E_UPG_LANGUSGE_MISMATCH 0x80000401 ///< �����̼����Բ�ƥ��
#define MV_E_UPG_CONFLICT          0x80000402 ///< ������ͻ���豸�Ѿ����������ٴ��������������ش˴���
#define MV_E_UPG_INNER_ERR         0x80000403 ///< ����ʱ����ڲ����ִ���
#define MV_E_UPG_UNKNOW            0x800004FF ///< ����ʱδ֪����





#endif //_MV_ERROR_DEFINE_H_
