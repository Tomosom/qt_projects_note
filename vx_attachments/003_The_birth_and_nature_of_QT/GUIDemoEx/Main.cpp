#include <windows.h>
#include "Application.h"
#include "MainWindow.h"
#include "PushButton.h"

BOOL WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Application a(hInstance, lpCmdLine);

    MainWindow w(hInstance, L"Main Window");

    PushButton b(&w, L"My Button");

    w.show();

    return a.exec();
}
