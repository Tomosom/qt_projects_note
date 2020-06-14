#include "Widget.h"
#include <QPainter>
#include <QFontMetrics>
#include <QFont>
#include <QRect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_sizeFactor = 0;

    m_timer.setParent(this);

    connect(&m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));

    m_timer.start(50);
}

void Widget::onTimeout()
{
    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;
    const QString text = "D.T.Software";
    QFont font("Comic Sans MS", 5 + (m_sizeFactor++) % 100);
    QFontMetrics metrics(font);
    const int w = metrics.width(text);
    const int h = metrics.height();
    QRect rect((width()-w)/2, (height()-h)/2, w, h);

    painter.begin(this);
    painter.setPen(Qt::blue);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, text);
    painter.end();
}

Widget::~Widget()
{
    
}
