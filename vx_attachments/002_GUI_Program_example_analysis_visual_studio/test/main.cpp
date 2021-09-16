#include <windows.h>

// L:在windows中表示使用宽字符，不是ASCII，而是utf8或Unicode编码
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
    // 每个应用程序都会返回一个值给操作系统，将参数0返回给操作系统，并退出自己
    // 0:告诉操作系统我们当前的应用程序时正常退出
    PostQuitMessage(0);
}

void Button_Handler(int id, int e)
{
    // 通过id判断按下的是哪个按钮，e:哪个动作
    if ((id == BUTTON_ID) && (e == BN_CLICKED)) {
        MessageBox(MainWindow, L"My button is clicked!", L"Click Message", 0);
    }
}

BOOL WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG Msg = {0};

    /* 1.自定义主窗口样式 */
    if (!DefineMainWindow(hInstance)) { // hInstance代表当前应用程序
        return FALSE;
    }

    /* 2.创建主窗口 */
    // hInstance代表当前应用程序，告诉操作系统，我们当前创建的窗口，就是当前应用程序使用的窗口
    MainWindow = CreateMainWindow(hInstance, STYLE_NAME);
    if (MainWindow) {
        /* 3.创建主窗口中的控件元素 */
        CreateButton(MainWindow, BUTTON_ID, L"My Button");
        /* 4.在屏幕上显示主窗口 */
        DisplayMainWindow(MainWindow, nCmdShow);
    } else {
        return FALSE;
    }

    /* 5.进入消息循环 */
    while (GetMessage(&Msg, NULL, NULL, NULL)) {
        /* 6.翻译并转换系统消息 */
        TranslateMessage(&Msg);
        /* 7.分发消息到对应的消息处理函数，WndProc */
        DispatchMessage(&Msg);
    }

    return TRUE;
}

BOOL DefineMainWindow(HINSTANCE hInstance)
{
    static WNDCLASS WndClass = {0}; // 系统结构体类型
                                    // 用于描述窗口样式
    WndClass.style         = 0;
    WndClass.cbClsExtra    = 0; // 窗口有哪些其他数据
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);          // 定义窗口背景色
    WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);     // 定义鼠标样式
    WndClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION); // 定义窗口左上角图标
    WndClass.hInstance     = hInstance;                       // 定义窗口式样属于当前应用程序
    WndClass.lpfnWndProc   = WndProc;                         // 窗口消息处理函数
    WndClass.lpszClassName = STYLE_NAME;                      // 窗口样式名，通过这个名字访问这个窗口式样
    WndClass.lpszMenuName  = NULL;

    /* 将定义好的窗口式样注册到系统 */
    return RegisterClass(&WndClass);
}

HWND CreateMainWindow(HINSTANCE hInstance, wchar_t* title)
{
    HWND hwnd = NULL;

    // 居中窗口
    int scrWidth = GetSystemMetrics(SM_CXSCREEN);
    int scrHeight = GetSystemMetrics(SM_CYSCREEN);
    int width = 600; // CW_USEDEFAULT
    int height = 200; // CW_USEDEFAULT

    hwnd = CreateWindow(STYLE_NAME,            // 通过定义好的窗口式样创建主窗口
                        title,                 // 主窗口标题
                        WS_OVERLAPPEDWINDOW,   // 创建后主窗口的显示风格
                        (scrWidth - width) / 2,   // 主窗口左上角 x 坐标
                        (scrHeight - height) / 2, // 主窗口左上角 y 坐标
                        width,                 // 主窗口宽度
                        height,                // 主窗口高度
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
    if (message == WM_DESTROY) {
        App_exit();
    }

    /* 按钮消息 */
    if (message == WM_COMMAND) {
        // LOWORD:获取参数的低位，HIWORD：获取参数的高位（用户的动作，按，拖拽等）
        Button_Handler(LOWORD(wParam), HIWORD(wParam));
    }

    /* 调用系统提供的默认消息处理函数 */
    // 比如最大化，最小化，拖动窗口调整大小（window的标准行为）
    return DefWindowProc(hWnd, message, wParam, lParam);
}

