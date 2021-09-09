#include "StringEvent.h"

StringEvent::StringEvent(QString data) : QEvent(TYPE)
{
    m_data = data;
}

QString StringEvent::data()
{
    return m_data;
}
