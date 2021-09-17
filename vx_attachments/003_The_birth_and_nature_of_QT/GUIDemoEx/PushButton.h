#pragma once

#include "Widget.h"

class PushButton : public Widget
{
public:
    PushButton(Widget* win, const wchar_t* text);
};