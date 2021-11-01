#include "Dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
        QDialog(parent), ModalBtn(this), ModelessBtn(this), MixedBtn(this)
{
    ModalBtn.setText("Modal Dialog");
    ModalBtn.move(20, 20);
    ModalBtn.resize(100, 30);

    ModelessBtn.setText("Modeless Dialog");
    ModelessBtn.move(20, 70);
    ModelessBtn.resize(100, 30);

    MixedBtn.setText("Mixed Dialog");
    MixedBtn.move(20, 120);
    MixedBtn.resize(100, 30);

    connect(&ModalBtn, SIGNAL(clicked()), this, SLOT(ModalBtn_Clicked()));
    connect(&ModelessBtn, SIGNAL(clicked()), this, SLOT(ModelessBtn_Clicked()));
    connect(&MixedBtn, SIGNAL(clicked()), this, SLOT(MixedBtn_Clicked()));

    resize(140, 170);
}

void Dialog::ModalBtn_Clicked()
{
    qDebug() << "ModalBtn_Clicked() Begin";

#if 0 /* 实验二: 对话框类型测试 */
    /* 模态对话框不论是否指定父子关系，模态对话框时钟显示在前面 */
    /* 一般情况下，都需指定父组件 */
    //QDialog dialog; /* 不指定父组件时，点击主窗口，子窗口不会闪 */
    QDialog dialog(this); /* 指定父组件时，点击父窗口，子窗口会闪 */
    dialog.exec();
#else /* 实验三: 返回值测试 */
    done(Accepted);
#endif

    qDebug() << "ModalBtn_Clicked() End";
}

void Dialog::ModelessBtn_Clicked()
{
    qDebug() << "ModelessBtn_Clicked() Begin";

#if 0 /* 实验二: 对话框类型测试 */
#if 0 /* 错误用法: 若在栈上定义,则会一闪而过 */
    QDialog dialog(this);
    dialog.show();
#else /* 在堆上创建 */
    //QDialog* dialog = new QDialog; /* 不指定父组件时, 则是独立的窗口, 不会始终位于主窗口的上面 */
    //QDialog* dialog = new QDialog(this); /* 指定父组件时, 始终位于父窗口的上面 */
    QDialog* dialog = new Dialog(this); /* 可用此对象测试Qt::WA_DeleteOnClose属性,查看析构函数~Dialog()的打印 */
    dialog->setAttribute(Qt::WA_DeleteOnClose); /* 关闭对话框时,释放内存空间,不同手动delete */
    dialog->show();
#endif
#else /* 实验三: 返回值测试 */
    done(Rejected);
#endif

    qDebug() << "ModelessBtn_Clicked() End";
}

/*
 * 混合对话框: 可理解为 非阻塞的模态对话框
 *           综合了非模态对话框和模态对话框的特性，
 *           在运行机理上是非模态对话框的特性，
 *           在表现形式上是模态对话框的特性。
 */
void Dialog::MixedBtn_Clicked()
{
    qDebug() << "MixedBtn_Clicked() Begin";

#if 0 /* 实验二: 对话框类型测试 */
    QDialog* dialog = new QDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setModal(true); /* 设置非模态对话框，行为类似模态对话框 */
    dialog->show();
#else /* 实验三: 返回值测试 */
    done(100);
#endif

    qDebug() << "MixedBtn_Clicked() End";
}

Dialog::~Dialog()
{
    qDebug() << "~Dialog()";
}
