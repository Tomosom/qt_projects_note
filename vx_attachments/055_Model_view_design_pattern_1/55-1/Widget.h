#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QFileSystemModel>
#include <QTreeView>

class Widget : public QWidget
{
    Q_OBJECT
    
    QFileSystemModel m_fsModel;
    QTreeView m_treeView;
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
