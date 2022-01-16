#include "Widget.h"
#include <QDebug>
#include <QEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent), myLineEdit(this)
{

}

bool Widget::event(QEvent* e)
{
    if (e->type() == QEvent::KeyPress) {
        qDebug() << "Widget::event";
    }

    return QWidget::event(e);
}

void Widget::keyPressEvent(QKeyEvent* e)
{
    qDebug() << "Widget::keyPressEvent";
    QWidget::keyPressEvent(e);
}

Widget::~Widget()
{
}
