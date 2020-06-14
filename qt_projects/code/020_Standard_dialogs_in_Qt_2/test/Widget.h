#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton ColorDialogBtn;
    QPushButton InputDialogBtn;
private slots:
    void ColorDialogBtn_Clicked();
    void InputDialogBtn_Clicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif
