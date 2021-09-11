#include <windows.h>

#define STYLE_NAME    L"MainForm"
#define BUTTON_ID     919

/* 主窗口定义函数 */
BOOL DefineMainWindow(HINSTANCE hInstance);
/* 主窗口创建函数 */
HWND CreateMainWindow(HINSTANCE hInstance, wchar_t* title);
/* 主窗口内部元素创建函数 */
HWND CreateButton(HWND parent, int id, wchar_t* text);
/* 主窗口显示函数 */
HWND DisplayMainWindow(HWND hWnd, int nCmdShow);
/* 主窗口消息处理函数 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

static HWND MainWindow = NULL; // 主窗口句柄标

void App_exit()
{
    PostQuitMessage(0);
}

void Button_Handler(int id, int e)
{
    if ( (id == BUTTON_ID) && (e == BN_CLICKED) ) {
        MessageBox(MainWindow, L"My button is clicked!", L"Click Message", 0);
    }
}

BOOL WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG Msg = {0};

    /* 1.自定义主窗口样式 */
    if( !DefineMainWindow(hInstance) )
    {
        return FALSE;
    }

    /* 2.创建主窗口 */
    MainWindow = CreateMainWindow(hInstance, STYLE_NAME);

    if( MainWindow )
    {
        /* 3.创建主窗口中的控件元素 */
        CreateButton(MainWindow, BUTTON_ID, L"My Button");

        /* 4.在屏幕上显示主窗口 */
        DisplayMainWindow(MainWindow, nCmdShow);
    }
    else
    {
        return FALSE;
    }

    /* 5.进入消息循环 */
    while( GetMessage(&Msg, NULL, NULL, NULL) )
    {
        /* 6.翻译并转换系统消息 */
        TranslateMessage(&Msg);
        /* 7.分发消息到对应的消息处理函数 */
        DispatchMessage(&Msg);
    }

    return TRUE;
}

BOOL DefineMainWindow(HINSTANCE hInstance)
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

HWND CreateMainWindow(HINSTANCE hInstance, wchar_t* title)
{
    HWND hwnd = NULL;

    hwnd = CreateWindow(STYLE_NAME,            // 通过定义好的窗口式样创建主窗口
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

    return hwnd;

}

HWND DisplayMainWindow(HWND hWnd, int nCmdShow)
{
    ShowWindow(hWnd,nCmdShow); // 显示窗口
    UpdateWindow(hWnd);        // 刷新窗口

    return hWnd;
}

HWND CreateButton(HWND parent, int id, wchar_t* text)
{
    HINSTANCE hInstance = (HINSTANCE)GetWindowLong(parent, GWL_HINSTANCE);
    HWND hwnd = NULL;

    hwnd = CreateWindow(L"button",                               // 通过系统预定义式样创建窗口元素
                        text,                                    // 窗口元素标题
                        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   // 窗口元素的显示风格
                        50,                                      // 窗口元素在窗口中的左上角 x 坐标
                        50,                                      // 窗口元素在窗口中的左上角 y 坐标
                        200,                                     // 窗口元素的宽度
                        60,                                      // 窗口元素的高度
                        parent,                                  // 窗口元素所在的父窗口
                        (HMENU)id,                               // 窗口元素 ID 值
                        hInstance,                               // 窗口元素属于当前应用程序
                        NULL);                                   // 窗口元素参数

    return hwnd;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    /* 处理退出消息 */
    if ( message == WM_DESTROY ) {
        App_exit();
    }

    /* 按钮消息 */
    if (message == WM_COMMAND) {
        Button_Handler(LOWORD(wParam), HIWORD(wParam));
    }

    /* 调用系统提供的默认消息处理函数 */
    return DefWindowProc(hWnd, message, wParam, lParam);
}
