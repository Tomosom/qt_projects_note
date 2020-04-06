#include <QCoreApplication>
#include <QDebug>
#include "TextMessage.h"
#include "TxtMsgAssembler.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TextMessage message("Demo", "Delphi Tang 狄泰软件学院！");
    QByteArray d = message.serialize();


    qDebug() << d;


    TxtMsgAssembler as;
    QSharedPointer<TextMessage> p;

    p = as.assemble(
                       d.data(),
                       d.length()
                   );

    qDebug() << p->type();
    qDebug() << p->length();
    qDebug() << p->data();

    return a.exec();
}
