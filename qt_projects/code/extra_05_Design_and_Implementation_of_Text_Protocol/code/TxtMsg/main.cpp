#include <QCoreApplication>
#include <QDebug>
#include "TextMessage.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TextMessage tm("AB", "1234567890");
    QString s = tm.serialize();

    qDebug() << s;

    TextMessage tmt;

    tmt.unserialize(s);

    qDebug() << tmt.type();
    qDebug() << tmt.length();
    qDebug() << tmt.data();

    return a.exec();
}
