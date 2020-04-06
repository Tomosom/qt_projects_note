#include "Widget.h"
#include <QGridLayout>

Widget::Widget(QWidget *parent) : QWidget(parent),
    TestBtn1(this), TestBtn2(this), TestBtn3(this), TestBtn4(this)
{
    //testGridLayout1();
    //testGridLayout2();
}

void Widget::testGridLayout1()
{
    QGridLayout* layout = new QGridLayout();

    TestBtn1.setText("Test Button 1");
    TestBtn1.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160, 30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160, 30);

    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160, 30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160, 30);

    layout->setSpacing(10);
    layout->addWidget(&TestBtn1, 0, 0);
    layout->addWidget(&TestBtn2, 0, 1);
    layout->addWidget(&TestBtn3, 1, 0);
    layout->addWidget(&TestBtn4, 1, 1);
    layout->setRowStretch(0, 1);
    layout->setRowStretch(1, 3);
    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 3);

    setLayout(layout);
}

void Widget::testGridLayout2()
{
    QGridLayout* layout = new QGridLayout();

    TestBtn1.setText("Test Button 1");
    TestBtn1.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160, 30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160, 30);

    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160, 30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160, 30);

    layout->setSpacing(10);
    layout->addWidget(&TestBtn1, 0, 0, 2, 1);
    layout->addWidget(&TestBtn2, 0, 1, 2, 1);
    layout->addWidget(&TestBtn3, 2, 0, 1, 2);
    layout->addWidget(&TestBtn4, 3, 0, 1, 2);

    setLayout(layout);
}

Widget::~Widget()
{
    
}
