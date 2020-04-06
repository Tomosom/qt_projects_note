#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

    int m_sizeFactor;
    QTimer m_timer;
protected slots:
    void onTimeout();
protected:
    void paintEvent(QPaintEvent *);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
