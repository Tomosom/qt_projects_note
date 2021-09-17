
#pragma once

#include "Widget.h"

class MainWindow : public Widget
{
protected:
    static const wchar_t STYLE_NAME[];

    /* 主窗口定义函数 */
    BOOL defineMainWindow(HINSTANCE hInstance);
    /* 主窗口创建函数 */
    void createMainWindow(HINSTANCE hInstance, const wchar_t* title);
    /* 主窗口消息处理函数 */
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
    MainWindow(HINSTANCE hInstance, const wchar_t* title);
    void show();
};
