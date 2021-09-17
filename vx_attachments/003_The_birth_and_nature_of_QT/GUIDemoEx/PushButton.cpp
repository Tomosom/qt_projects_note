
#include "PushButton.h"

PushButton::PushButton(Widget* win, const wchar_t* text)
{
    HINSTANCE hInstance = (HINSTANCE)GetWindowLong(win->hwnd(), GWL_HINSTANCE);

    m_hwnd = CreateWindow(L"button",                               // ͨ��ϵͳԤ����ʽ����������Ԫ��
                          text,                                    // ����Ԫ�ر���
                          WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   // ����Ԫ�ص���ʾ���
                          50,                                      // ����Ԫ���ڴ����е����Ͻ� x ����
                          50,                                      // ����Ԫ���ڴ����е����Ͻ� y ����
                          200,                                     // ����Ԫ�صĿ��
                          60,                                      // ����Ԫ�صĸ߶�
                          win->hwnd(),                             // ����Ԫ�����ڵĸ�����
                          (HMENU)this,                             // ����Ԫ�� ID ֵ
                          hInstance,                               // ����Ԫ�����ڵ�ǰӦ�ó���
                          NULL);                                   // ����Ԫ�ز���
}
