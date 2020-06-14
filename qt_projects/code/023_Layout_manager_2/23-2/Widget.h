#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton TestBtn1;
    QPushButton TestBtn2;
    QPushButton TestBtn3;
    QPushButton TestBtn4;

    void testGridLayout1();
    void testGridLayout2();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif
