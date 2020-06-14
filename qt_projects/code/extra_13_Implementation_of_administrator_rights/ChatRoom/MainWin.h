#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QListWidget>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QMap>
#include <QMenu>
#include "QLoginDialog.h"
#include "ClientDemo.h"
#include "TxtMsgHandler.h"

class MainWin : public QWidget, public TxtMsgHandler
{
    Q_OBJECT

    typedef void(MainWin::*MSGHandler)(QTcpSocket&, TextMessage&);

    QVBoxLayout vMainLayout;
    QGroupBox msgGrpBx;
    QListWidget listWidget;
    QMenu listWidgetMenu;
    QGroupBox inputGrpBx;
    QPlainTextEdit msgEditor;
    QLineEdit inputEdit;
    QPushButton logInOutBtn;
    QPushButton sendBtn;
    QLabel statusLbl;
    QLoginDialog loginDlg;

    ClientDemo m_client;
    QString m_level;
    QMap<QString, MSGHandler> m_handlerMap;

    void initMember();
    void initMsgGrpBx();
    void initInputGrpBx();
    void initListWidgetMenu();
    void connectSlots();

    void setCtrlEnabled(bool enabled);
    QString getCheckedUserId();

    void CONN_Handler(QTcpSocket&, TextMessage&);
    void DSCN_Handler(QTcpSocket&, TextMessage&);
    void LIOK_Handler(QTcpSocket&, TextMessage&);
    void LIER_Handler(QTcpSocket&, TextMessage&);
    void MSGA_Handler(QTcpSocket&, TextMessage&);
    void USER_Handler(QTcpSocket&, TextMessage&);
    void CTRL_Handler(QTcpSocket&, TextMessage&);
private slots:
    void sendBtnClicked();
    void logInOutBtnClicked();
    void listWidgetMenuClicked();
    void listWidgetContextMenu(const QPoint&);
public:
    MainWin(QWidget *parent = 0);
    void handle(QTcpSocket& obj, TextMessage& message);
    ~MainWin();
};

#endif // MAINWIN_H
