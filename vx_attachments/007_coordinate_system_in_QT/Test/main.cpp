#include <QtGui/QApplication>
#include <QPushButton>
#include <QDebug>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

#if 1
    QPushButton b(&w); // 生成QPushButton对象,其父组件为QWidget
    QPushButton b1(&w);
    b.setText("Button");  // 设置显示的字符串
    b.move(10, 10);       // 移动坐标
    b.resize(100, 25);    // 设置大小
    b1.setText("Button"); // 设置显示的字符串
    b1.move(110, 10);     // 移动坐标
    b1.resize(100, 25);   // 设置大小
#endif

    w.resize(220, 300);

#if 0
    /*
     * 当我们设置的宽度如果小于操作系统所需要满足的最小宽度时，
     * 会以操作系统对窗口规定的最小宽度来取代设定的值
     */
    w.resize(1, 1);
#endif

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
