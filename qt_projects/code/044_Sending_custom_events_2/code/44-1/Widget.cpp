#include "Widget.h"
#include "StringEvent.h"
#include <QMouseEvent>
#include <QDebug>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_edit(this)
{
    m_edit.installEventFilter(this);
}

bool Widget::event(QEvent* evt)
{
    if( evt->type() == QMouseEvent::MouseButtonDblClick )
    {
        qDebug() << "event: Before sentEvent";

        StringEvent e("D.T.Software");

        QApplication::sendEvent(&m_edit, &e);

        qDebug() << "event: After sentEvent";
    }

    return QWidget::event(evt);
}

bool Widget::eventFilter(QObject* obj, QEvent* evt)
{
    if( (obj == &m_edit) && (evt->type() == StringEvent::TYPE) )
    {
        StringEvent* se = dynamic_cast<StringEvent*>(evt);

        qDebug() << "Receive: " << se->data();

        m_edit.insert(se->data());

        return true;
    }

    return QWidget::eventFilter(obj, evt);
}

Widget::~Widget()
{
    
}
