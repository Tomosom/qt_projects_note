#include "Widget.h"
#include <QStackedLayout>
#include <QHBoxLayout>

#if START_TIMER
#include <QtCore>
#endif

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
#if START_TIMER
    QTimer* timer = new QTimer(this);
#endif
    TestBtn1.setText("1st Button");
    TestBtn2.setText("2rd Button");
    TestBtn3.setText("3th Button");
    TestBtn4.setText("Test Button 4: D.T.Software");

    TestBtn2.setParent(widget);
    TestBtn3.setParent(widget);

    hLayout->addWidget(&TestBtn2);
    hLayout->addWidget(&TestBtn3);

    widget->setLayout(hLayout); //栈式布局管理器间接嵌套

    sLayout->addWidget(&TestBtn1); // 0
    sLayout->addWidget(widget); // 1
    sLayout->addWidget(&TestBtn4); // 2

    sLayout->setCurrentIndex(0);

    setLayout(sLayout);

#if START_TIMER
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeout()));
    timer->start(2000); // 2s
#endif
}

#if START_TIMER
void Widget::timerTimeout()
{
    //qDebug() << "triggered";

    //layout()这个成员函数会将当前组件所拥有的布局管理器返回
    QStackedLayout* sLayout = dynamic_cast<QStackedLayout*>(layout());

    if( sLayout != NULL )
    {
        int index = (sLayout->currentIndex() + 1) % sLayout->count();

        sLayout->setCurrentIndex(index);
    }
}
#endif

Widget::~Widget()
{
    
}
