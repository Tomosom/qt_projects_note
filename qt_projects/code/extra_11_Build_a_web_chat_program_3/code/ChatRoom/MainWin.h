#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include "QLoginDialog.h"
#include "ClientDemo.h"
#include "TxtMsgHandler.h"

class MainWin : public QWidget, public TxtMsgHandler
{
    Q_OBJECT

    typedef void(MainWin::*MSGHandler)(QTcpSocket&, TextMessage&);

    QVBoxLayout vMainLayout;
    QGroupBox msgGrpBx;
    QGroupBox inputGrpBx;
    QPlainTextEdit msgEditor;
    QLineEdit inputEdit;
    QPushButton logInOutBtn;
    QPushButton sendBtn;
    QLabel statusLbl;
    QLoginDialog loginDlg;

    ClientDemo m_client;
    QMap<QString, MSGHandler> m_handlerMap;

    void initMember();
    void initMsgGrpBx();
    void initInputGrpBx();
    void connectSlots();

    void setCtrlEnabled(bool enabled);

    void CONN_Handler(QTcpSocket&, TextMessage&);
    void DSCN_Handler(QTcpSocket&, TextMessage&);
    void LIOK_Handler(QTcpSocket&, TextMessage&);
    void LIER_Handler(QTcpSocket&, TextMessage&);
    void MSGA_Handler(QTcpSocket&, TextMessage&);
private slots:
    void sendBtnClicked();
    void logInOutBtnClicked();
public:
    MainWin(QWidget *parent = 0);
    void handle(QTcpSocket& obj, TextMessage& message);
    ~MainWin();
};

#endif // MAINWIN_H
