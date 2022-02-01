#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>

class Widget : public QWidget
{
    Q_OBJECT
protected:
    void dragEnterEvent(QDragEnterEvent *e); // 拖
    void dropEvent(QDropEvent *e); // 放
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
