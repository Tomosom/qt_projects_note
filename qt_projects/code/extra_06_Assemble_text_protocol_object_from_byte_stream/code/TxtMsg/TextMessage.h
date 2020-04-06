#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

#include <QObject>

class TextMessage : public QObject
{
    QString m_type;
    QString m_data;

public:
    TextMessage(QObject* parent = NULL);
    TextMessage(QString type, QString data, QObject* parent = NULL);

    QString type();
    int length();
    QString data();

    QString serialize();
    bool unserialize(QString s);
};

#endif // TEXTMESSAGE_H
