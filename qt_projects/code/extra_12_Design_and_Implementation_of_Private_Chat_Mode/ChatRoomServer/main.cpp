#include <QCoreApplication>
#include "ServerHandler.h"
#include "ServerDemo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ServerHandler handler;
    ServerDemo server;

    server.setHandler(&handler);
    server.start(8890);

    return a.exec();
}
