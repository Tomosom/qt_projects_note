
#include "Application.h"

Application::Application(HINSTANCE hInstance, LPSTR lpCmdLine)
{

}

bool Application::exec()
{
    MSG Msg = {0};

    /* ������Ϣѭ�� */
    while( GetMessage(&Msg, NULL, NULL, NULL) )
    {
        /* ���벢ת��ϵͳ��Ϣ */
        TranslateMessage(&Msg);
        /* �ַ���Ϣ����Ӧ����Ϣ������ */
        DispatchMessage(&Msg);
    }

    return TRUE;
}