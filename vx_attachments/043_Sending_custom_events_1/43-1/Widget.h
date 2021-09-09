#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
    
    QPushButton m_pushButton;

    void testSendEvent();
    void testPostEvent();
protected slots:
    void onButtonClicked();
public:
    Widget(QWidget *parent = 0);
    bool event(QEvent* evt);
    ~Widget();
};

#endif // WIDGET_H
