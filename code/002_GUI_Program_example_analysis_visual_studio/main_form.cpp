#include <windows.h>

#define STYLE_NAME    L"MainForm"
#define BUTTON_ID     919

/* �����ڶ��庯�� */
BOOL DefineMainWindow(HINSTANCE hInstance);
/* �����ڴ������� */
HWND CreateMainWindow(HINSTANCE hInstance, wchar_t* title);
/* �������ڲ�Ԫ�ش������� */
HWND CreateButton(HWND parent, int id, wchar_t* text);
/* ��������ʾ���� */
HWND DisplayMainWindow(HWND hWnd, int nCmdShow);
/* ��������Ϣ������ */
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

static HWND MainWindow = NULL; // �����ھ����

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

    /* 1.�Զ�����������ʽ */
    if( !DefineMainWindow(hInstance) )
    {
        return FALSE;
    }

    /* 2.���������� */
    MainWindow = CreateMainWindow(hInstance, STYLE_NAME);

    if( MainWindow )
    {
        /* 3.�����������еĿؼ�Ԫ�� */
        CreateButton(MainWindow, BUTTON_ID, L"My Button");

        /* 4.����Ļ����ʾ������ */
        DisplayMainWindow(MainWindow, nCmdShow);
    }
    else
    {
        return FALSE;
    }

    /* 5.������Ϣѭ�� */
    while( GetMessage(&Msg, NULL, NULL, NULL) )
    {
        /* 6.���벢ת��ϵͳ��Ϣ */
        TranslateMessage(&Msg);
        /* 7.�ַ���Ϣ����Ӧ����Ϣ������ */
        DispatchMessage(&Msg);
    }

    return TRUE;
}

BOOL DefineMainWindow(HINSTANCE hInstance)
{
    static WNDCLASS WndClass = {0}; // ϵͳ�ṹ������
                                    // ��������������ʽ
    WndClass.style         = 0;
    WndClass.cbClsExtra    = 0;
    WndClass.cbClsExtra    = 0;
    WndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW);          // ���崰�ڱ���ɫ
    WndClass.hCursor       = LoadCursor(NULL, IDC_ARROW);     // ���������ʽ
    WndClass.hIcon         = LoadIcon(NULL, IDI_APPLICATION); // ���崰�����Ͻ�ͼ��
    WndClass.hInstance     = hInstance;                       // ���崰��ʽ�����ڵ�ǰӦ�ó���
    WndClass.lpfnWndProc   = WndProc;                         // ������Ϣ������
    WndClass.lpszClassName = STYLE_NAME;                      // ������ʽ��
    WndClass.lpszMenuName  = NULL;

    /* ������õĴ���ʽ��ע�ᵽϵͳ */
    return RegisterClass(&WndClass);
}

HWND CreateMainWindow(HINSTANCE hInstance, wchar_t* title)
{
    HWND hwnd = NULL;

    hwnd = CreateWindow(STYLE_NAME,            // ͨ������õĴ���ʽ������������
                        title,                 // �����ڱ���
                        WS_OVERLAPPEDWINDOW,   // �����������ڵ���ʾ���
                        CW_USEDEFAULT,         // ���������Ͻ� x ����
                        CW_USEDEFAULT,         // ���������Ͻ� y ����
                        CW_USEDEFAULT,         // �����ڿ��
                        CW_USEDEFAULT,         // �����ڸ߶�
                        NULL,                  // ������
                        NULL,                  // ���ڲ˵���
                        hInstance,             // ���������ڵ�ǰӦ�ó���
                        NULL);                 // ���ڲ���

    return hwnd;

}

HWND DisplayMainWindow(HWND hWnd, int nCmdShow)
{
    ShowWindow(hWnd,nCmdShow); // ��ʾ����
    UpdateWindow(hWnd);        // ˢ�´���

    return hWnd;
}

HWND CreateButton(HWND parent, int id, wchar_t* text)
{
    HINSTANCE hInstance = (HINSTANCE)GetWindowLong(parent, GWL_HINSTANCE);
    HWND hwnd = NULL;

    hwnd = CreateWindow(L"button",                               // ͨ��ϵͳԤ����ʽ����������Ԫ��
                        text,                                    // ����Ԫ�ر���
                        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,   // ����Ԫ�ص���ʾ���
                        50,                                      // ����Ԫ���ڴ����е����Ͻ� x ����
                        50,                                      // ����Ԫ���ڴ����е����Ͻ� y ����
                        200,                                     // ����Ԫ�صĿ��
                        60,                                      // ����Ԫ�صĸ߶�
                        parent,                                  // ����Ԫ�����ڵĸ�����
                        (HMENU)id,                               // ����Ԫ�� ID ֵ
                        hInstance,                               // ����Ԫ�����ڵ�ǰӦ�ó���
                        NULL);                                   // ����Ԫ�ز���

	return hwnd;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	/* �����˳���Ϣ */
	if ( message == WM_DESTROY ) {
		App_exit();
		
	}

	/* ��ť��Ϣ */
	if (message == WM_COMMAND) {
		Button_Handler(LOWORD(wParam), HIWORD(wParam));
	}

    /* ����ϵͳ�ṩ��Ĭ����Ϣ������ */
    return DefWindowProc(hWnd, message, wParam, lParam);
}
