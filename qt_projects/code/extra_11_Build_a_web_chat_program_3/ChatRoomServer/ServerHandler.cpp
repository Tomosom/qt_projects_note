#include "ServerHandler.h"
#include <QDebug>

ServerHandler::ServerHandler()
{
    m_handlerMap.insert("CONN", CONN_Handler);
    m_handlerMap.insert("DSCN", DSCN_Handler);
    m_handlerMap.insert("LGIN", LGIN_Handler);
    m_handlerMap.insert("MSGA", MSGA_Handler);
}

void ServerHandler::handle(QTcpSocket& obj, TextMessage& message)
{
    if( m_handlerMap.contains(message.type()) )
    {
        MSGHandler handler = m_handlerMap.value(message.type());

        (this->*handler)(obj, message);
    }
}

void ServerHandler::CONN_Handler(QTcpSocket&, TextMessage&)
{

}

void ServerHandler::DSCN_Handler(QTcpSocket& obj, TextMessage&)
{
    for(int i=0; i<m_nodeList.length(); i++)
    {
        Node* n = m_nodeList.at(i);

        if( n->socket == &obj )
        {
            n->socket = NULL;
            break;
        }
    }
}

void ServerHandler::MSGA_Handler(QTcpSocket&, TextMessage& message)
{
    const QByteArray& ba = message.serialize();

    for(int i=0; i<m_nodeList.length(); i++)
    {
        Node* n = m_nodeList.at(i);

        if( n->socket != NULL )
        {
            n->socket->write(ba);
        }
    }
}

void ServerHandler::LGIN_Handler(QTcpSocket& obj, TextMessage& message)
{
    QString data = message.data();
    int index = data.indexOf('\r');
    QString id = data.mid(0, index);
    QString pwd = data.mid(index + 1);
    QString result = "";

    index = -1;

    for(int i=0; i<m_nodeList.length(); i++)
    {
        if( id == m_nodeList.at(i)->id )
        {
            index = i;
            break;
        }
    }

    if( index == -1 )
    {
        Node* newNode = new Node();

        if( newNode != NULL )
        {
            newNode->id = id;
            newNode->pwd = pwd;
            newNode->socket = &obj;

            m_nodeList.append(newNode);

            result = "LIOK";
        }
        else
        {
            result = "LIER";
        }
    }
    else
    {
        Node* n = m_nodeList.at(index);

        if( pwd == n->pwd )
        {
            n->socket = &obj;

            result = "LIOK";
        }
        else
        {
            result = "LIER";
        }
    }

    obj.write(TextMessage(result, id).serialize());
}
