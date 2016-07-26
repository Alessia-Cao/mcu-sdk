// ��������
// �����ڹ����ж���� CHASSIS_PLATFORM

#include "navipack_api.h"

#define NAVI_MAX(a, b) (a>b?a:b)
#define NAVI_MAX_BLOCK (u32)(NAVI_MAX(NAVI_MAX( sizeof(NaviPack_CtrlType), sizeof(NaviPack_StatusType)), sizeof(NaviPack_ConfigType)))
#define NAVIPACK_COMM_SIZE (NAVI_MAX_BLOCK + sizeof(NaviPack_HeadType) + 1)

NavipackComm_Type Comm;

u8 RecvBuf[NAVIPACK_COMM_SIZE];
u8 SendBuf[NAVIPACK_COMM_SIZE*2+6];

void Boost(void)
{
    NaviPack_HeadType head = {
            NAVIPACK_SLAVE_ID,
            FUNC_ID_READ_STATUS,
            0,
            sizeof(NaviPack_StatusType),
        };
        
    if(NaviPack_TxProcessor(&Comm, head))
    {
        // �ɹ�������ָ���ļĴ�������
    }
}

void Recv(void)
{
    u8* data;
    u32 len, i;
    
    len = RecvData(data); // �û����򣬴�ͨѶ�ӿڽ�������
        
    for(i=0; i<len; i++)
    {
        if(NaviPack_RxProcessor(&comm, data[i]))
        {
            //�ɹ�������һ���Ĵ�������
        }
    }
}

int main(void)
{
    // ��ʼ��
    Comm.rxBuffer = RecvBuf;
    Comm.rxSize = sizeof(RecvBuf);    
    Comm.txBuffer = SendBuf;
    Comm.txSize = sizeof(SendBuf);
    
    NaviPack_Init();
    
    while(1)
    {
        Recv();
        
        // ��״̬�Ĵ�����ֵ
        NaviPack_Global.status.lineVelocity = v;        
        // 10 ms ����һ�Σ�����״̬�Ĵ�����ֵ
        Boost();
    }
}
