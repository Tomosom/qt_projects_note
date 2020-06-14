#include "Widget.h"
#include <QPainter>
#include <QPointF>
#include <QPen>
#include <qmath.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;

    pen.setColor(Qt::green);
    pen.setStyle(Qt::SolidLine);
    pen.setWidthF(0.01);

    painter.setPen(pen);

    painter.setViewport(50, 50, width()-100, height()-100);
    painter.setWindow(-10, 2, 20, -4); // (-10, 2)    (10, -2)

    painter.fillRect(-10, 2, 20, -4, Qt::black);

    painter.drawLine(QPointF(-10, 0), QPointF(10, 0));   // x
    painter.drawLine(QPointF(0, 2), QPointF(0, -2));     // y

    for(float x=-10; x<10; x+=0.01)
    {
        float y = qSin(x);

        painter.drawPoint(QPointF(x, y));
    }

}

Widget::~Widget()
{
    
}
