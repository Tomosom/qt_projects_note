
#include "MainWindow.h"

const wchar_t MainWindow::STYLE_NAME[] = L"MainForm";

MainWindow::MainWindow(HINSTANCE hInstance, const wchar_t* title) : Widget(NULL)
{
    defineMainWindow(hInstance);

    createMainWindow(hInstance, title);
}

void MainWindow::show()
{
    ShowWindow(m_hwnd, SW_SHOWNORMAL); // ��ʾ����
    UpdateWindow(m_hwnd);              // ˢ�´���
}

BOOL MainWindow::defineMainWindow(HINSTANCE hInstance)
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

void MainWindow::createMainWindow(HINSTANCE hInstance, const wchar_t* title)
{
	// ���д���
    int scrWidth = GetSystemMetrics(SM_CXSCREEN);
    int scrHeight = GetSystemMetrics(SM_CYSCREEN);
    int width = 600; // CW_USEDEFAULT
    int height = 200; // CW_USEDEFAULT
	m_hwnd = CreateWindow(STYLE_NAME,            // ͨ������õĴ���ʽ������������
                          title,                 // �����ڱ���
                          WS_OVERLAPPEDWINDOW,   // �����������ڵ���ʾ���
						  (scrWidth - width) / 2,   // ���������Ͻ� x ����
						  (scrHeight - height) / 2, // ���������Ͻ� y ����
						  width,                 // �����ڿ��
						  height,                // �����ڸ߶�
						  NULL,                  // ������
						  NULL,                  // ���ڲ˵���
						  hInstance,             // ���������ڵ�ǰӦ�ó���
						  NULL);                 // ���ڲ���
#if 0
    m_hwnd = CreateWindow(STYLE_NAME,            // ͨ������õĴ���ʽ������������
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
#endif
}

LRESULT CALLBACK MainWindow::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
    }
    /* ����ϵͳ�ṩ��Ĭ����Ϣ������ */
    return DefWindowProc(hwnd, message, wParam, lParam);
}

