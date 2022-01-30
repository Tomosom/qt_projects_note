#include "Widget.h"
#include <QDebug>
#include <QEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent), myLineEdit(this)
{

}

/* 重载函数 */
bool Widget::event(QEvent* e)
{
    if (0) {
        /* 程序启动时，下面语句会打印多条，表示操作系统发送过来的消息是多种多样的，转换得到的QT对象也是多种多样的 */
        qDebug() << "all event: " << e->type();
    }

    if (e->type() == QEvent::KeyPress) {
        qDebug() << "Widget::event";
    }

    return QWidget::event(e); /* 调用父类的事件处理函数 */
}

/* 重载函数 */
void Widget::keyPressEvent(QKeyEvent* e)
{
    // 重载的两个事件处理函数：event和keyPressEvent，
    // 会先调用event，再调用keyPressEvent。当按下键盘上的按键后，产生的QT事件首先被event成员函数处理，
    // 在event成员函数的内部会根据事件的类型进而调用keyPressEvent这个事件处理函数来进行具体的处理
    qDebug() << "Widget::keyPressEvent";
    QWidget::keyPressEvent(e); /* 调用父类的事件处理函数 */
}

Widget::~Widget()
{
}
