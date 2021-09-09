#include <QtGui/QApplication>
#include <QPushButton>
#include <QDebug>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QPushButton b(&w);  // ����QPushButton����,�丸���ΪQWidget
    QPushButton b1(&w);

    b.setText("Button");    //������ʾ���ַ���
    b.move(10, 10);         // �ƶ�����
    b.resize(100, 25);      // ���ô�С

    b1.setText("Button");    //������ʾ���ַ���
    b1.move(110, 10);         // �ƶ�����
    b1.resize(100, 25);      // ���ô�С

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
