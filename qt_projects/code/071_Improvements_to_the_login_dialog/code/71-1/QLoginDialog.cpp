#include "QLoginDialog.h"
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QMessageBox>

QLoginDialog::QLoginDialog(QWidget* parent) : QDialog(parent, Qt::WindowCloseButtonHint),
    UserLabel(this), PwdLabel(this), CaptLabel(this),
    UserEdit(this), PwdEdit(this), CaptEdit(this),
    LoginBtn(this), CancelBtn(this)
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
    PwdEdit.setEchoMode(QLineEdit::Password);

    CaptLabel.setText("Captcha:");
    CaptLabel.move(20, 100);
    CaptLabel.resize(60, 25);

    CaptEdit.move(85, 100);
    CaptEdit.resize(85, 25);

    CancelBtn.setText("Cancel");
    CancelBtn.move(85, 145);
    CancelBtn.resize(85, 30);

    LoginBtn.setText("Login");
    LoginBtn.move(180, 145);
    LoginBtn.resize(85, 30);

    m_timer.setParent(this);

    setWindowTitle("Login");
    setFixedSize(285, 205);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(Timer_Timeout()));
    connect(&LoginBtn, SIGNAL(clicked()), this, SLOT(LoginBtn_Clicked()));
    connect(&CancelBtn, SIGNAL(clicked()), this, SLOT(CancelBtn_Clicked()));

    qsrand(QTime::currentTime().second() * 1000 + QTime::currentTime().msec());

    m_captcha = getCaptcha();
    m_colors = getColors();

    m_timer.start(100);
}

void QLoginDialog::LoginBtn_Clicked()
{
    qDebug() << "LoginBtn_Clicked() Begin";

    QString captcha = CaptEdit.text().replace(" ", "");

    if( m_captcha.toLower() == captcha.toLower() )
    {
        m_user = UserEdit.text().trimmed();
        m_pwd = PwdEdit.text();

        if( m_user == "" )
        {
            QMessageBox::information(this, "Info", "User ID can NOT be empty!");
        }
        else if( m_pwd == "" )
        {
            QMessageBox::information(this, "Info", "Password can NOT be empty!");
        }
        else
        {
            done(Accepted);
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "The captcha is NOT matched!");

        m_captcha = getCaptcha();

        CaptEdit.selectAll();
    }

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

void QLoginDialog::Timer_Timeout()
{
    m_colors = getColors();

    update();
}

void QLoginDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(180, 100, 84, 24, Qt::white);

    painter.setFont(QFont("Comic Sans MS", 12));

    for(int i=0; i<150; i++)
    {
        painter.setPen(m_colors[i%4]);
        painter.drawPoint(180 + qrand() % 84, 100 + qrand() % 24);
    }

    for(int i=0; i<4; i++)
    {
        painter.setPen(m_colors[i]);
        painter.drawText(180 + 20 * i, 100, 20, 24, Qt::AlignCenter, QString(m_captcha[i]));
    }
}

QString QLoginDialog::getCaptcha()
{
    QString ret = "";

    for(int i=0; i<4; i++)
    {
        int c = (qrand() % 2) ? 'a' : 'A';

        ret += static_cast<QChar>(c + qrand() % 26);
    }

    return ret;
}

Qt::GlobalColor* QLoginDialog::getColors()
{
    static Qt::GlobalColor colors[4];

    for(int i=0; i<4; i++)
    {
        colors[i] = static_cast<Qt::GlobalColor>(2 + qrand() % 16);
    }

    return colors;
}

QLoginDialog::~QLoginDialog()
{

}

