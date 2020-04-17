#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>

#define START_TIMER 1

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton TestBtn1;
    QPushButton TestBtn2;
    QPushButton TestBtn3;
    QPushButton TestBtn4;

    void initControl();
#if START_TIMER
private slots:
    void timerTimeout();
#endif
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif
