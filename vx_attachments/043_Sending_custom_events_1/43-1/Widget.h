#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT
    
    QPushButton m_sendEventButton;
    QPushButton m_postEventButton;

protected slots:
    void onSendEventButtonClicked();
    void onPostEventButtonClicked();
public:
    Widget(QWidget *parent = 0);
    bool event(QEvent* evt);
    ~Widget();
};

#endif // WIDGET_H
