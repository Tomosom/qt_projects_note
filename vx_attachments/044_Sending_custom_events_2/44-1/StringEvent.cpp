#include "StringEvent.h"

StringEvent::StringEvent(QString data) : QEvent(TYPE) // 对父类进行初始化为TYPE
{
    m_data = data;
}

QString StringEvent::data()
{
    return m_data;
}
