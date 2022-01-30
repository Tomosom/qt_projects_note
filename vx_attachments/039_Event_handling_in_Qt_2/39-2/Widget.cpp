#include "Widget.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

Widget::Widget(QWidget *parent) : QWidget(parent), myLineEdit(this)
{
    myLineEdit.installEventFilter(this); // 安装事件过滤器对象
}

bool Widget::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        qDebug() << "Widget::event";
    }

    return QWidget::event(e);
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "Widget::keyPressEvent";

    QWidget::keyPressEvent(e);
}

bool Widget::eventFilter(QObject *obj, QEvent *e)
{
    bool ret = true;

    if ((obj == &myLineEdit) && (e->type() == QEvent::KeyPress)) {
        qDebug() << "Widget::eventFilter";
        //ret = false;
#if 1
        QKeyEvent *evt = dynamic_cast<QKeyEvent*>(e);
        switch (evt->key()) {
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
            ret = false; // 若是可接受的按键就传递下去
            break;
        default:
            break; // 若不可接受的按键就没收掉 (bug:中文切英文的时候仍会传下去?)
        }
#endif
    } else {
        ret = QWidget::eventFilter(obj, e); // 调用父类的函数
    }

    return ret;
}

Widget::~Widget()
{

}
