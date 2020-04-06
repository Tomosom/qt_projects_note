#include "Widget.h"
#include <QDebug>

void onMyButtonMouseRelease(QObject* sender, QMouseEvent* e)
{
    qDebug() << "onMyButtonMouseRelease(QObject* sender, QMouseEvent* e)";
}

Widget::Widget(QWidget *parent) : QWidget(parent), myButton(this, onMyButtonMouseRelease)
{
    myButton.setText("QMyPushButton");

    connect(&myButton, SIGNAL(clicked()), this, SLOT(onMyButtonClicked()));
}

void Widget::onMyButtonClicked()
{
    qDebug() << "onMyButtonClicked()";
}


Widget::~Widget()
{
    
}
