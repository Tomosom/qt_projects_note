#include "Widget.h"
#include <QVBoxLayout>


Widget::Widget(QWidget *parent) : QWidget(parent),
    TestBtn1(this), TestBtn2(this), TestBtn3(this), TestBtn4(this)
{
    //initControl();
    //testVBoxLayout();
    //testHBoxLayout();
    //testVHBoxLayout();
}

void Widget::testVHBoxLayout()
{
    QHBoxLayout* hLayout1 = new QHBoxLayout();
    QHBoxLayout* hLayout2 = new QHBoxLayout();
    QVBoxLayout* vLayout = new QVBoxLayout();

    TestBtn1.setText("Test Button 1");
    TestBtn1.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn1.setMinimumSize(160, 30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn2.setMinimumSize(160, 30);

    hLayout1->setSpacing(10);
    hLayout1->addWidget(&TestBtn1);
    hLayout1->addWidget(&TestBtn2);

    TestBtn3.setText("Test Button 3");
    TestBtn3.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn3.setMinimumSize(160, 30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    TestBtn4.setMinimumSize(160, 30);

    hLayout2->setSpacing(10);
    hLayout2->addWidget(&TestBtn3);
    hLayout2->addWidget(&TestBtn4);

    vLayout->setSpacing(10);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->setStretchFactor(hLayout1, 1);
    vLayout->setStretchFactor(hLayout2, 3);

    setLayout(vLayout);
}

void Widget::testHBoxLayout()
{
    QHBoxLayout* layout = new QHBoxLayout();

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

    layout->setSpacing(30);
    layout->addWidget(&TestBtn1);
    layout->addWidget(&TestBtn2);
    layout->addWidget(&TestBtn3);
    layout->addWidget(&TestBtn4);
    layout->setStretchFactor(&TestBtn1, 1);
    layout->setStretchFactor(&TestBtn2, 2);
    layout->setStretchFactor(&TestBtn3, 1);
    layout->setStretchFactor(&TestBtn4, 3);

    setLayout(layout);
}

void Widget::testVBoxLayout()
{
    QVBoxLayout* layout = new QVBoxLayout();

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

    layout->setSpacing(30);
    layout->addWidget(&TestBtn1);
    layout->addWidget(&TestBtn2);
    layout->addWidget(&TestBtn3);
    layout->addWidget(&TestBtn4);
    layout->setStretch(0, 1);
    layout->setStretch(1, 1);
    layout->setStretch(2, 2);
    layout->setStretch(3, 2);

    setLayout(layout);
}

void Widget::initControl()
{
    TestBtn1.setText("Test Button 1");
    TestBtn1.move(20, 20);
    TestBtn1.resize(160, 30);

    TestBtn2.setText("Test Button 2");
    TestBtn2.move(20, 70);
    TestBtn2.resize(160, 30);

    TestBtn3.setText("Test Button 3");
    TestBtn3.move(20, 120);
    TestBtn3.resize(160, 30);

    TestBtn4.setText("Test Button 4");
    TestBtn4.move(20, 170);
    TestBtn4.resize(160, 30);
}

Widget::~Widget()
{
    
}
