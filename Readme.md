# ʹ��˵��
## ��ֲ
1. �� `navipack_type.h` �����ȱ�ٵ��������ͣ��� bool s32 �ȣ���֤�����ܹ�˳��ͨ����
2. ����������ֲ��Ҫ�� `navipack_api.c` �е� `RxProcessor()` �����µ� `switch` ������û��Լ���Ҫ�Ĵ���
3. �������ݵ���ֲ��Ҫ�� `navipack_api.c` �е� `Navipack_SendData()` ���������ʵ�ʽ����ݷ��ͳ�ȥ�Ĵ���
����˵���� `navipack_api.c` ���� `// TODO:` ע�͸�������ʾ

## ����
`main.c` ���ǵ�������
1. Ϊ���ͺͽ��շֱ�׼�� Buffer��
2. ���� `NavipackComm_Type` ���͵ı������� Buffer ָ��ֱ�ֵ���ñ����� `rxBuffer` �� `txBuffer` ��Ա��
3. ͬʱ������ Buffer �ĳߴ縳ֵ�����ϱ����� `rxSize` �� `txSize` ��Ա��
4. ����Ҫ��� byte �ĵ��� `NaviPack_RxProcessor()` �ӿڡ�
5. ����Ҫ�ȶ���һ�� `NaviPack_HeadType` ���͵ı����������Ӧ��ֵ������ `startAddr` ����Ҫ���͵������ڼĴ����е�ƫ�ơ�
6. Ȼ���� NaviPack_Global ȫ�ֱ����������Ӧ��ֵ���ٵ��� `NaviPack_TxProcessor()` �ӿڼ��ɡ�