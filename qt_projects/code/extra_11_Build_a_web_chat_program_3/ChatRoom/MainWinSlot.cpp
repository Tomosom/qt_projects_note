#include "MainWin.h"
#include <QMessageBox>
#include <QDebug>

void MainWin::initMember()
{
    m_client.setHandler(this);

    m_handlerMap.insert("CONN", CONN_Handler);
    m_handlerMap.insert("DSCN", DSCN_Handler);
    m_handlerMap.insert("LIOK", LIOK_Handler);
    m_handlerMap.insert("LIER", LIER_Handler);
    m_handlerMap.insert("MSGA", MSGA_Handler);
}

void MainWin::sendBtnClicked()
{
    QString text = inputGrpBx.title() + ":\n" + "    " + inputEdit.text() + "\n";
    TextMessage tm("MSGA", text);

    if( m_client.send(tm) )
    {
        inputEdit.clear();
    }
}

void MainWin::logInOutBtnClicked()
{
    if( !m_client.isValid() )
    {
        if( loginDlg.exec() == QDialog::Accepted )
        {
            QString usr = loginDlg.getUser().trimmed();
            QString pwd = loginDlg.getPwd();

            if( m_client.connectTo("127.0.0.1", 8890) )
            {
                TextMessage tm("LGIN", usr + '\r' + pwd);

                m_client.send(tm);
            }
            else
            {
                QMessageBox::critical(this, "失败", "连接不到远程服务端！");
            }
        }
    }
    else
    {
        m_client.close();
    }
}

void MainWin::handle(QTcpSocket& obj, TextMessage& message)
{
    if( m_handlerMap.contains(message.type()) )
    {
        MSGHandler handler = m_handlerMap.value(message.type());

        (this->*handler)(obj, message);
    }
}

void MainWin::CONN_Handler(QTcpSocket&, TextMessage&)
{

}

void MainWin::MSGA_Handler(QTcpSocket&, TextMessage& message)
{
    msgEditor.appendPlainText(message.data());
}

void MainWin::DSCN_Handler(QTcpSocket&, TextMessage&)
{
    setCtrlEnabled(false);

    inputGrpBx.setTitle("用户名");
}

void MainWin::LIOK_Handler(QTcpSocket&, TextMessage& message)
{
    setCtrlEnabled(true);

    inputGrpBx.setTitle(message.data());
}

void MainWin::LIER_Handler(QTcpSocket&, TextMessage&)
{
    QMessageBox::critical(this, "错误", "身份验证失败！");

    m_client.close();
}

MainWin::~MainWin()
{
    m_client.close();
}

