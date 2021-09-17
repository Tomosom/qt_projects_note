
#pragma once

#include "Widget.h"

class MainWindow : public Widget
{
protected:
    static const wchar_t STYLE_NAME[];

    /* �����ڶ��庯�� */
    BOOL defineMainWindow(HINSTANCE hInstance);
    /* �����ڴ������� */
    void createMainWindow(HINSTANCE hInstance, const wchar_t* title);
    /* ��������Ϣ������ */
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
    MainWindow(HINSTANCE hInstance, const wchar_t* title);
    void show();
};
