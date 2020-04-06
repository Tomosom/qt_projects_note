#include "MainWin.h"
#include <QHBoxLayout>
#include <QGridLayout>

MainWin::MainWin(QWidget *parent)
    : QWidget(parent), loginDlg(this)
{
    initMember();
    initMsgGrpBx();
    initInputGrpBx();
    connectSlots();

    vMainLayout.setSpacing(10);
    vMainLayout.addWidget(&msgGrpBx);
    vMainLayout.addWidget(&inputGrpBx);

    setWindowTitle("狄泰聊天室");
    setLayout(&vMainLayout);
    setMinimumSize(550, 400);
    resize(550, 400);
}

void MainWin::connectSlots()
{
    connect(&sendBtn, SIGNAL(clicked(bool)), this, SLOT(sendBtnClicked()));
    connect(&logInOutBtn, SIGNAL(clicked(bool)), this, SLOT(logInOutBtnClicked()));
}

void MainWin::initMsgGrpBx()
{
    QHBoxLayout* hbl = new QHBoxLayout();

    hbl->setContentsMargins(2, 5, 2, 2);
    hbl->addWidget(&msgEditor);

    msgEditor.setReadOnly(true);

    msgGrpBx.setLayout(hbl);
    msgGrpBx.setTitle("聊天消息");
}

void MainWin::initInputGrpBx()
{
    QGridLayout* gl = new QGridLayout();

    gl->setSpacing(10);
    gl->addWidget(&inputEdit, 0, 0, 1, 5);
    gl->addWidget(&statusLbl, 1, 0, 1, 3);
    gl->addWidget(&logInOutBtn, 1, 3);
    gl->addWidget(&sendBtn, 1, 4);

    inputEdit.setFixedHeight(23);
    inputEdit.setEnabled(false);
    statusLbl.setText("状态: 未登录");
    logInOutBtn.setFixedHeight(30);
    logInOutBtn.setText("登录");
    sendBtn.setFixedHeight(30);
    sendBtn.setText("发送");
    sendBtn.setEnabled(false);

    inputGrpBx.setFixedHeight(100);
    inputGrpBx.setLayout(gl);
    inputGrpBx.setTitle("用户名");
}

void MainWin::setCtrlEnabled(bool enabled)
{
    inputEdit.setEnabled(enabled);
    statusLbl.setText(enabled ? "状态: 连接成功" : "状态: 未登录");
    logInOutBtn.setText(enabled ? "退出" : "登录");
    sendBtn.setEnabled(enabled);

    if( !enabled )
    {
        msgEditor.clear();
    }
}
