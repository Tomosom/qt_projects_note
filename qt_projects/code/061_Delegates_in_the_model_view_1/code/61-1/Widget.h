#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include "SubStyledItemDelegate.h"

class Widget : public QWidget
{
    Q_OBJECT
    
    QTableView m_view;
    QStandardItemModel m_model;
    QPushButton m_testBtn;
    SubStyledItemDelegate m_delegate;

    void initView();
    void initModel();

private slots:
    void onTestBtnClicked();
public:
    Widget(QWidget* parent = 0);
    ~Widget();
};

#endif // WIDGET_H
