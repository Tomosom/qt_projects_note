#include "QLoginDialog.h"

#include <QDebug>

QLoginDialog::QLoginDialog(QWidget* parent) : QDialog(parent, Qt::WindowCloseButtonHint),
    UserLabel(this), PwdLabel(this), UserEdit(this), PwdEdit(this), LoginBtn(this), CancelBtn(this)
{
    UserLabel.setText("User ID:");
    UserLabel.move(20, 30);
    UserLabel.resize(60, 25);

    UserEdit.move(85, 30);
    UserEdit.resize(180, 25);

    PwdLabel.setText("Password:");
    PwdLabel.move(20, 65);
    PwdLabel.resize(60,25);

    PwdEdit.move(85, 65);
    PwdEdit.resize(180, 25);
    PwdEdit.setEchoMode(QLineEdit::Password); // 设置编辑框密码显示为*号

    CancelBtn.setText("Cancel");
    CancelBtn.move(85, 110);
    CancelBtn.resize(85, 30);

    LoginBtn.setText("Login");
    LoginBtn.move(180, 110);
    LoginBtn.resize(85, 30);

    setWindowTitle("Login");
    setFixedSize(285, 170); // 对话框的大小不可变

    connect(&LoginBtn, SIGNAL(clicked()), this, SLOT(LoginBtn_Clicked()));
    connect(&CancelBtn, SIGNAL(clicked()), this, SLOT(CancelBtn_Clicked()));
}

void QLoginDialog::LoginBtn_Clicked()
{
    qDebug() << "LoginBtn_Clicked() Begin";

    m_user = UserEdit.text().trimmed(); // trimmed表示把前后的空格去掉
    m_pwd = PwdEdit.text();

    done(Accepted); // done()函数返回

    qDebug() << "LoginBtn_Clicked() End";
}

void QLoginDialog::CancelBtn_Clicked()
{
    qDebug() << "CancelBtn_Clicked() Begin";

    done(Rejected);

    qDebug() << "CancelBtn_Clicked() End";
}

QString QLoginDialog::getUser()
{
    return m_user;
}

QString QLoginDialog::getPwd()
{
    return m_pwd;
}

QLoginDialog::~QLoginDialog()
{

}

