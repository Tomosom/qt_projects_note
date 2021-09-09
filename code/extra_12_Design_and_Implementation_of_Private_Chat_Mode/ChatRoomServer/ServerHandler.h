#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <QTcpSocket>
#include <QList>
#include <QMap>
#include "TextMessage.h"
#include "TxtMsgHandler.h"

class ServerHandler : public TxtMsgHandler
{
    typedef void(ServerHandler::*MSGHandler)(QTcpSocket&, TextMessage&);

    struct  Node
    {
        QString id;
        QString pwd;
        QTcpSocket* socket;

    public:
        Node() : id(""), pwd(""), socket(NULL)
        {

        }
    };

    QList<Node*> m_nodeList;
    QMap<QString, MSGHandler> m_handlerMap;

    QString getOnlineUserId();
    void sendToAllOnlineUser(TextMessage&);

    void CONN_Handler(QTcpSocket&, TextMessage&);
    void DSCN_Handler(QTcpSocket&, TextMessage&);
    void LGIN_Handler(QTcpSocket&, TextMessage&);
    void MSGA_Handler(QTcpSocket&, TextMessage&);
    void MSGP_Handler(QTcpSocket&, TextMessage&);
public:
    ServerHandler();
    void handle(QTcpSocket& obj, TextMessage& message);
};

#endif // SERVERHANDLER_H
