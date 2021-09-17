
#include "PushButton.h"

PushButton::PushButton(Widget* win, const wchar_t* text)
{
    HINSTANCE hInstance = (HINSTANCE)GetWindowLong(win->hwnd(), GWL_HINSTANCE);

    m_hwnd = CreateWindow(L"button",                               // 通过系统预定义式样创建窗口元素
                          text,                                    // 窗口元素标题
                          WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   // 窗口元素的显示风格
                          50,                                      // 窗口元素在窗口中的左上角 x 坐标
                          50,                                      // 窗口元素在窗口中的左上角 y 坐标
                          200,                                     // 窗口元素的宽度
                          60,                                      // 窗口元素的高度
                          win->hwnd(),                             // 窗口元素所在的父窗口
                          (HMENU)this,                             // 窗口元素 ID 值
                          hInstance,                               // 窗口元素属于当前应用程序
                          NULL);                                   // 窗口元素参数
}
