#include <ntddk.h>

// �ṩһ��Unload����ֻ��Ϊ���ó����ܹ���̬ж��,�������
VOID DriverUnload(PDRIVER_OBJECT driver)
{
    // ����ʵ��������ʲô��������ֻ��ӡһ�仰:
    DbgPrint("first: Our driver is unloading��\r\n");
}

// DriverEntry����ں������൱��main��
NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)
{
#if DBG
    _asm int 3
#endif
    // �������ǵ��ں�ģ�����ڣ�����������д��������д�Ķ�����
    DbgPrint("first: Hello world!");

    // ����һ��ж�غ�����������������˳���
    driver->DriverUnload = DriverUnload;

    return STATUS_SUCCESS;
}