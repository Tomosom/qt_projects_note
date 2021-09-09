#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QTableView>
#include <QListView>
#include <QTreeView>
#include <QStandardItemModel>

class Widget : public QWidget
{
    Q_OBJECT
    
    QStandardItemModel m_model;
    QTableView m_tableView;
    QListView m_listView;
    QTreeView m_treeView;

    void initModel();
    void initView();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
