#include "Widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.save();

    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 16));
    painter.rotate(0);
    painter.drawText(30, 40, "D.T.Software");

    painter.setPen(Qt::red);
    painter.setFont(QFont("Comic Sans MS", 20));
    painter.rotate(20);
    painter.drawText(30, 40, "D.T.Software");

    painter.restore();

    painter.drawText(130, 140, "D.T.Software");
}

Widget::~Widget()
{
    
}
