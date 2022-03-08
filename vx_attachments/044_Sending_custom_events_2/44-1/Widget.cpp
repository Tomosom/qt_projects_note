#include "Widget.h"
#include "StringEvent.h"
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>

Widget::Widget(QWidget *parent) : QWidget(parent), m_edit(this)
{
    m_edit.installEventFilter(this);
    this->resize(200, 100);
}

bool Widget::event(QEvent* evt)
{
    if (evt->type() == QMouseEvent::MouseButtonDblClick) {
        // 这样的双击的动作为什么不用槽函数来完成？而是通过重写事件处理函数来完成？
        // 因为QWidgrt这个类并没有提供双击相关的信号
        qDebug() << "event: Before sentEvent";

        StringEvent e("D.T.Software");

        QApplication::sendEvent(&m_edit, &e);

        qDebug() << "event: After sentEvent";
    }

    return QWidget::event(evt);
}

bool Widget::eventFilter(QObject* obj, QEvent* evt)
{
    if ((obj == &m_edit) && (evt->type() == StringEvent::TYPE)) {
        StringEvent* se = dynamic_cast<StringEvent*>(evt); // 父类转化为子类，用dynamic_cast

        qDebug() << "Receive: " << se->data(); // 此处使用的是父类eventFilter的方式，也可以重写QLineEdit的event函数进行处理

        m_edit.insert(se->data());

        return true; // 复习：返回true代表当前事件已经被处理了，不用再传递到目标对象上去
    }

    return QWidget::eventFilter(obj, evt);
}

Widget::~Widget()
{
}
