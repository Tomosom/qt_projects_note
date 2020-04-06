#include <QtGui/QApplication>
#include <QPushButton>
#include <QDebug>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QPushButton b(&w);  // 生成QPushButton对象,其父组件为QWidget
    QPushButton b1(&w);

    b.setText("Button");    //设置显示的字符串
    b.move(10, 10);         // 移动坐标
    b.resize(100, 25);      // 设置大小

    b1.setText("Button");    //设置显示的字符串
    b1.move(110, 10);         // 移动坐标
    b1.resize(100, 25);      // 设置大小

    w.resize(220, 300);
    w.move(120, 120);

    w.show();
    
    qDebug()<<"QWidget : ";
    qDebug()<<w.x();
    qDebug()<<w.y();
    qDebug()<<w.width();
    qDebug()<<w.height();

    qDebug()<<"QWidget::geometry() : ";
    qDebug()<<w.geometry().x();
    qDebug()<<w.geometry().y();
    qDebug()<<w.geometry().width();
    qDebug()<<w.geometry().height();

    qDebug()<<"QWidget::frameGeometry() : ";
    qDebug()<<w.frameGeometry().x();
    qDebug()<<w.frameGeometry().y();
    qDebug()<<w.frameGeometry().width();
    qDebug()<<w.frameGeometry().height();

    return a.exec();
}
