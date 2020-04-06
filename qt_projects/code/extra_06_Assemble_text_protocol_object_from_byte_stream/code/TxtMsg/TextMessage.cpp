#include "TextMessage.h"


TextMessage::TextMessage(QObject* parent) : QObject(parent)
{
    m_type = "";
    m_data = "";
}

TextMessage::TextMessage(QString type, QString data, QObject* parent) : QObject(parent)
{
    m_type = type.trimmed();

    m_type.resize(4, ' ');

    m_data = data.mid(0, 0xFFFF);
}

QString TextMessage::type()
{
    return m_type.trimmed();
}

int TextMessage::length()
{
    return m_data.length();
}

QString TextMessage::data()
{
    return m_data;
}

QString TextMessage::serialize()
{
    QString len = QString::asprintf("%X", m_data.length());

    len.resize(4, ' ');

    return m_type + len + m_data;
}

bool TextMessage::unserialize(QString s)
{
    bool ret = (s.length() >= 8);

    if( ret )
    {
        QString type = s.mid(0, 4);
        QString len = s.mid(4, 4).trimmed();
        int l = len.toInt(&ret, 16);

        ret = ret && (l == (s.length() - 8));

        if( ret )
        {
            m_type = type;
            m_data = s.mid(8, l);
        }
    }

    return ret;
}
