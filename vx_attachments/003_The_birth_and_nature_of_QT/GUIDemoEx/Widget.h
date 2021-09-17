#pragma once

#include <windows.h>

class Widget
{
protected:
    Widget* m_parent;
    HWND m_hwnd;
public:
    Widget();
    Widget(Widget* parent);
    HWND hwnd();
    Widget* parent();
};