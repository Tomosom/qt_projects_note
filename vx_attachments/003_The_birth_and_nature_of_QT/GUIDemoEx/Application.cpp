
#include "Application.h"

Application::Application(HINSTANCE hInstance, LPSTR lpCmdLine)
{

}

bool Application::exec()
{
    MSG Msg = {0};

    /* 进入消息循环 */
    while(GetMessage(&Msg, NULL, NULL, NULL)) {
        /* 翻译并转换系统消息 */
        TranslateMessage(&Msg);
        /* 分发消息到对应的消息处理函数 */
        DispatchMessage(&Msg);
    }

    return TRUE;
}