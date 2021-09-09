#include <QCoreApplication>
#include <QTcpSocket>
#include <QDebug>
#include <QThread>
#include "ClientDemo.h"
#include "ServerDemo.h"

void SyncClientDemo()
{
    QTcpSocket client;
    char buf[256] = {0};

    client.connectToHost("127.0.0.1", 8080);

    qDebug() << "Connected:" << client.waitForConnected();

    qDebug() << "Send Bytes:" << client.write("D.T.Software");

    qDebug() << "Send Status:" << client.waitForBytesWritten();

    qDebug() << "Data Available:" << client.waitForReadyRead();

    qDebug() << "Received Bytes:" << client.read(buf, sizeof(buf)-1);

    qDebug() << "Received Data:" << buf;

    client.close();

    // client.waitForDisconnected();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ServerDemo server;

    server.start(8080);

    return a.exec();
}
