#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTabWidget>

class Widget : public QWidget
{
    Q_OBJECT
    
    QTabWidget m_tabWidget;
protected slots:
    void onTabCurrentChanged(int index);
    void onTabCloseRequested(int index);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
