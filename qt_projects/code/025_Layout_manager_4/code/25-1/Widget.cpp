#include "Widget.h"
#include <QStackedLayout>
#include <QHBoxLayout>
#include <QtCore>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent),
    TestBtn1(this), TestBtn2(this), TestBtn3(this), TestBtn4(this)
{
    initControl();
}

void Widget::initControl()
{
    QStackedLayout* sLayout = new QStackedLayout();
    QHBoxLayout* hLayout = new QHBoxLayout();
    QWidget* widget = new QWidget();
    QTimer* timer = new QTimer(this);

    TestBtn1.setText("1st Button");
    TestBtn2.setText("2rd Button");
    TestBtn3.setText("3th Button");
    TestBtn4.setText("Test Button 4: D.T.Software");

    TestBtn2.setParent(widget);
    TestBtn3.setParent(widget);

    hLayout->addWidget(&TestBtn2);
    hLayout->addWidget(&TestBtn3);

    widget->setLayout(hLayout);

    sLayout->addWidget(&TestBtn1); // 0
    sLayout->addWidget(widget); // 1
    sLayout->addWidget(&TestBtn4); // 2

    sLayout->setCurrentIndex(0);

    setLayout(sLayout);

    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));

    timer->start(2000);
}

void Widget::timerTimeout()
{
    QStackedLayout* sLayout = dynamic_cast<QStackedLayout*>(layout());

    if( sLayout != NULL )
    {
        int index = (sLayout->currentIndex() + 1) % sLayout->count();

        sLayout->setCurrentIndex(index);
    }
}

Widget::~Widget()
{
    
}
