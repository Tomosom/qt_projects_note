#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton TestBtn;
private slots:
    void TestBtn_Clicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif
