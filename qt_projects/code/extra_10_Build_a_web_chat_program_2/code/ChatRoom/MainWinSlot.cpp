#include "MainWin.h"
#include <QMessageBox>
#include <QDebug>

void MainWin::initMember()
{
    m_client.setHandler(this);
}

void MainWin::sendBtnClicked()
{

}

void MainWin::logInOutBtnClicked()
{
    if( loginDlg.exec() == QDialog::Accepted )
    {
        QString usr = loginDlg.getUser().trimmed();
        QString pwd = loginDlg.getPwd();

        if( m_client.connectTo("127.0.0.1", 8890) )
        {
            setCtrlEnabled(true);
        }
        else
        {
            QMessageBox::critical(this, "失败", "连接不到远程服务端！");
        }
    }
}

void MainWin::handle(QTcpSocket& obj, TextMessage& message)
{
    qDebug() << message.type();
    qDebug() << message.data();
}
