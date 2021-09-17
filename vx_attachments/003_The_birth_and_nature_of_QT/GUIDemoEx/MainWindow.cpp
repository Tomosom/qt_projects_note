
#include "MainWindow.h"

const wchar_t MainWindow::STYLE_NAME[] = L"MainForm";

MainWindow::MainWindow(HINSTANCE hInstance, const wchar_t* title) : Widget(NULL)
{
    defineMainWindow(hInstance);

    createMainWindow(hInstance, title);
}

void MainWindow::show()
{
    ShowWindow(m_hwnd, SW_SHOWNORMAL); // 显示窗口
    UpdateWindow(m_hwnd);              // 刷新窗口
}

BOOL MainWindow::defineMainWindow(HINSTANCE hInstance)
{
    static WNDCLASS WndClass = {0}; // 系统结构体类型
                                    // 用于描述窗口样式
    WndClass.style         = 0;
    WndClass.cbClsExtra    = 0;
    WndClass.cbClsExtra    = 0;
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);          // 定义窗口背景色
    WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);     // 定义鼠标样式
    WndClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION); // 定义窗口左上角图标
    WndClass.hInstance     = hInstance;                       // 定义窗口式样属于当前应用程序
    WndClass.lpfnWndProc   = WndProc;                         // 窗口消息处理函数
    WndClass.lpszClassName = STYLE_NAME;                      // 窗口样式名
    WndClass.lpszMenuName  = NULL;

    /* 将定义好的窗口式样注册到系统 */
    return RegisterClass(&WndClass);
}

void MainWindow::createMainWindow(HINSTANCE hInstance, const wchar_t* title)
{
    m_hwnd = CreateWindow(STYLE_NAME,            // 通过定义好的窗口式样创建主窗口
                          title,                 // 主窗口标题
                          WS_OVERLAPPEDWINDOW,   // 创建后主窗口的显示风格
                          CW_USEDEFAULT,         // 主窗口左上角 x 坐标
                          CW_USEDEFAULT,         // 主窗口左上角 y 坐标
                          CW_USEDEFAULT,         // 主窗口宽度
                          CW_USEDEFAULT,         // 主窗口高度
                          NULL,                  // 父窗口
                          NULL,                  // 窗口菜单栏
                          hInstance,             // 主窗口属于当前应用程序
                          NULL);                 // 窗口参数
}

LRESULT CALLBACK MainWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch(message)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    /* 调用系统提供的默认消息处理函数 */
    return DefWindowProc(hwnd, message, wParam, lParam);
}

