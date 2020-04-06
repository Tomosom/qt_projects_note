#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QPushButton FontDialogBtn;
    QPushButton ProgressDialogBtn;
    QPushButton PrintDialogBtn;
private slots:
    void FontDialogBtn_Clicked();
    void PrintDialogBtn_Clicked();
    void ProgressDialogBtn_Clicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif
