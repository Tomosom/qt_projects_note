#include "Dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
        QDialog(parent), ModalBtn(this), NormalBtn(this), MixedBtn(this)
{
    ModalBtn.setText("Modal Dialog");
    ModalBtn.move(20, 20);
    ModalBtn.resize(100, 30);

    NormalBtn.setText("Normal Dialog");
    NormalBtn.move(20, 70);
    NormalBtn.resize(100, 30);

    MixedBtn.setText("Mixed Dialog");
    MixedBtn.move(20, 120);
    MixedBtn.resize(100, 30);

    connect(&ModalBtn, SIGNAL(clicked()), this, SLOT(ModalBtn_Clicked()));
    connect(&NormalBtn, SIGNAL(clicked()), this, SLOT(NormalBtn_Clicked()));
    connect(&MixedBtn, SIGNAL(clicked()), this, SLOT(MixedBtn_Clicked()));

    resize(140, 170);
}

void Dialog::ModalBtn_Clicked()
{
    qDebug() << "ModalBtn_Clicked() Begin";

#if 0
    /* 对话框类型测试 */
    QDialog dialog(this);
    dialog.exec();
#else
    /* 返回值测试 */
    done(Accepted);
#endif
    qDebug() << "ModalBtn_Clicked() End";
}

void Dialog::NormalBtn_Clicked()
{
    qDebug() << "NormalBtn_Clicked() Begin";
#if 0
    /* 对话框类型测试 */
#if 0
    /* 若在栈上定义,则会一闪而过 */
    //QDialog dialog;
    QDialog dialog(this); // 是否指定父组件,效果都是一样的
    dialog.show();
#else
    /* 在堆上创建 */
    //QDialog* dialog = new QDialog; // 若不指定父组件,则是独立的窗口
    //QDialog* dialog = new QDialog(this); // 默认是非模态对话框,且始终位于父窗口的上面
    QDialog* dialog = new Dialog(this); // 可用此对象测试Qt::WA_DeleteOnClose属性

    dialog->setAttribute(Qt::WA_DeleteOnClose); // 关闭对话框时,释放内存空间
    dialog->show();
#endif
#else
    /* 返回值测试 */
    done(Rejected);
#endif

    qDebug() << "NormalBtn_Clicked() End";
}

void Dialog::MixedBtn_Clicked()
{
    qDebug() << "MixedBtn_Clicked() Begin";
#if 0
    /* 对话框类型测试 */
    QDialog* dialog = new QDialog(this);

    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setModal(true);
    dialog->show();
#else
    /* 返回值测试 */
    done(100);
#endif
    qDebug() << "MixedBtn_Clicked() End";
}

Dialog::~Dialog()
{
    qDebug() << "~Dialog()";
}
