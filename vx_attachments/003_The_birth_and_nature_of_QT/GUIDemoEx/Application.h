
#pragma once

#include <windows.h>

class Application
{
public:
    Application(HINSTANCE hInstance, LPSTR lpCmdLine);
    bool exec();
};