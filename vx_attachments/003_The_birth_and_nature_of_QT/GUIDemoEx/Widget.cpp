#include "Widget.h"

Widget::Widget()
{
    m_parent = NULL;
}


Widget::Widget(Widget* parent)
{
    m_parent = parent;
}

HWND Widget::hwnd()
{
    return m_hwnd;
}

Widget* Widget::parent()
{
    return m_parent;
}