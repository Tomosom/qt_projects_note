#include "Widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

Widget::Widget(QWidget *parent) : QWidget(parent),
    SimpleMsgBtn(this), CustomMsgBtn(this), OpenFileBtn(this), SaveFileBtn(this)
{
    SimpleMsgBtn.setText("Simple Message Dialog");
    SimpleMsgBtn.move(20, 20);
    SimpleMsgBtn.resize(160, 30);

    CustomMsgBtn.setText("Custom Message Dialog");
    CustomMsgBtn.move(20, 70);
    CustomMsgBtn.resize(160, 30);

    OpenFileBtn.setText("Open File Dialog");
    OpenFileBtn.move(20, 120);
    OpenFileBtn.resize(160, 30);

    SaveFileBtn.setText("Save File Dialog");
    SaveFileBtn.move(20, 170);
    SaveFileBtn.resize(160, 30);

    resize(200, 220);
    setFixedSize(200, 220);

    connect(&SimpleMsgBtn, SIGNAL(clicked()), this, SLOT(SimpleMsgBtn_Clicked()));
    connect(&CustomMsgBtn, SIGNAL(clicked()), this, SLOT(CustomMsgBtn_Clicked()));
    connect(&OpenFileBtn, SIGNAL(clicked()), this, SLOT(OpenFileBtn_Clicked()));
    connect(&SaveFileBtn, SIGNAL(clicked()), this, SLOT(SaveFileBtn_Clicked()));
}

void Widget::SimpleMsgBtn_Clicked()
{
    QMessageBox msg(this);
    msg.setText("This is a message dialog!");
    msg.exec();
}

void Widget::CustomMsgBtn_Clicked()
{
#if 0
    QMessageBox msg(this);

    msg.setWindowTitle("Window Title");
    msg.setText("This is a detail message dialog!");
    msg.setIcon(QMessageBox::Information); // 弹出对话框时会有声音
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll);

    if (msg.exec() == QMessageBox::Ok) {
        qDebug() << "Ok button is clicked!";
    }
#else /* 简化写法 */
    if (QMessageBox::information(this,"Window Title", "this is box!",
        QMessageBox::Ok | QMessageBox::Cancel | QMessageBox::YesToAll) == QMessageBox::Ok) {
        qDebug() << "Ok button is clicked!";
    }
#endif
}

void Widget::OpenFileBtn_Clicked()
{
    QFileDialog dlg(this);

    dlg.setAcceptMode(QFileDialog::AcceptOpen);
    dlg.setFilter("Image(*.png *.xpm *.jpg);;Text(*.txt);;All(*.*)");
    dlg.setFileMode(QFileDialog::ExistingFiles);

    if (dlg.exec() == QFileDialog::Accepted) {
        QStringList fs = dlg.selectedFiles();
        for (int i = 0; i < fs.count(); i++) {
            qDebug() << fs[i];
        }
    }
}

void Widget::SaveFileBtn_Clicked()
{
    QFileDialog dlg(this);

    dlg.setAcceptMode(QFileDialog::AcceptSave);
    dlg.setFilter("Text(*.txt)");

    if (dlg.exec() == QFileDialog::Accepted) {
        QStringList fs = dlg.selectedFiles();
        for (int i = 0; i < fs.count(); i++) {
            qDebug() << fs[i];
        }
    }
}

Widget::~Widget()
{
}
