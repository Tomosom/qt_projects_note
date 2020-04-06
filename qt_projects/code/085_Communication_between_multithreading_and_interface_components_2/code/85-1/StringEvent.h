#ifndef _STRINGEVENT_H_
#define _STRINGEVENT_H_

#include <QEvent>
#include <QString>

class StringEvent : public QEvent
{
    QString m_data;
public:
    const static Type TYPE = static_cast<Type>(QEvent::User + 0xFF);

    explicit StringEvent(QString data = "");
    QString data();
    
};

#endif // _STRINGEVENT_H_
