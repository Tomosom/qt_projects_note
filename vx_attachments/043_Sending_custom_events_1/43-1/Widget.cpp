#include "Widget.h"
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_sendEventButton.setParent(this);
    m_sendEventButton.setText("sendEvent");
    m_sendEventButton.move(0, 0);
    connect(&m_sendEventButton, SIGNAL(clicked()), this, SLOT(onSendEventButtonClicked()));

    m_postEventButton.setParent(this);
    m_postEventButton.setText("postEvent");
    m_postEventButton.move(0, 50);
    connect(&m_postEventButton, SIGNAL(clicked()), this, SLOT(onPostEventButtonClicked()));
}

void Widget::onSendEventButtonClicked()
{
    // 事件类型：鼠标的双击事件QEvent::MouseButtonDblClick
    // 在QPoint(0, 0)进行的双击
    // Qt::LeftButton鼠标的左键进行的双击
    // Qt::NoButton??
    // Qt::NoModifier指明双击时没有按键盘上任意一个键
    QMouseEvent dbcEvt(QEvent::MouseButtonDblClick, QPoint(0, 0),
                       Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

    qDebug() << "Before sendEvent()";
    QApplication::sendEvent(this, &dbcEvt); // this:发送到当前窗口上
    qDebug() << "After sendEvent()";
}

void Widget::onPostEventButtonClicked()
{
    // 注：事件对象在堆中创建，发送出去后，在被处理完的同时，会被Qt平台释放掉
    QMouseEvent* dbcEvt = new QMouseEvent(QEvent::MouseButtonDblClick, QPoint(0, 0),
                                          Qt::LeftButton, Qt::NoButton, Qt::NoModifier);

    qDebug() << "Before postEvent()";
    QApplication::postEvent(this, dbcEvt);
    qDebug() << "After postEvent()";
}

/* 实验现象：
1.双击空白处，打印：
    event():  QMouseEvent(MouseButtonDblClick, 1, 1, 0)
2.点击sendEvent，打印：
    Before sendEvent()
    event():  QMouseEvent(MouseButtonDblClick, 1, 0, 0)
    After sendEvent()
3.点击postEvent，打印：
    Before postEvent()
    After postEvent()
    event():  QMouseEvent(MouseButtonDblClick, 1, 0, 0)
    解析：QApplication::postEvent是在槽函数的上下文中被调用的，槽函数被调用的上下文就是事件处理函数的内部。
    也就是说我们单击一个按钮的时候，就会产生一个事件，这个事件就会被事件处理函数所处理。在按钮的单机事件处理函数
    内部，调用了这个槽函数。当前处理的是按钮的单击事件，在按钮单击事件的槽函数内部，我们postEvent了一个事件到
    事件队列里边去。那么当前事件都还没被处理完，不会去处理事件队列里边其他事件。因此有如上打印的顺序。
*/
bool Widget::event(QEvent* evt)
{
    if (evt->type() == QEvent::MouseButtonDblClick) {
        qDebug() << "event(): " << evt;
    }

    return QWidget::event(evt);
}

Widget::~Widget()
{
}
