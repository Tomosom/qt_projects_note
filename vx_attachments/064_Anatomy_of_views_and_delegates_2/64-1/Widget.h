#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QTimer>
#include "CustomizedItemDelegate.h"

class Widget : public QWidget
{
    Q_OBJECT
    
    QTableView m_view;
    QStandardItemModel m_model;
    CustomizedItemDelegate m_delegate;
    QTimer m_timer;

    void initView();
    void initModel();
private slots:
    void timerTimeout();
public:
    Widget(QWidget* parent = 0);
    ~Widget();
};

#endif // WIDGET_H
