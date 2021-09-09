#include <QCoreApplication>
#include <QDebug>
#include "TextMessage.h"
#include "TxtMsgAssembler.h"
#include "TxtMsgHandler.h"
#include "ClientDemo.h"
#include "ServerDemo.h"

class Handler : public TxtMsgHandler
{
public:
    void handle(QTcpSocket& socket, TextMessage& message)
    {
        qDebug() << &socket;
        qDebug() << message.type();
        qDebug() << message.length();
        qDebug() << message.data();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TextMessage message("Demo", "Delphi Tang 狄泰软件学院！");
    Handler handler;
    ServerDemo server;
    ClientDemo client;

    server.setHandler(&handler);
    server.start(8890);

    client.setHandler(&handler);
    client.connectTo("127.0.0.1", 8890);
    client.send(message);

    return a.exec();
}
