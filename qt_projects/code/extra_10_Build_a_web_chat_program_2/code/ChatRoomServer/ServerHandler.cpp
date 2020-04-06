#include "ServerHandler.h"
#include <QDebug>

ServerHandler::ServerHandler()
{

}

void ServerHandler::handle(QTcpSocket& obj, TextMessage& message)
{
    qDebug() << &obj;
    qDebug() << message.type();
    qDebug() << message.data();

    if( message.type() == "CONN" )
    {

    }
    else if( message.type() == "DSCN" )
    {

    }
}
