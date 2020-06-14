#include "Widget.h"
#include <QStandardItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent, Qt::WindowContextHelpButtonHint)
{
    initModel();
    initView();

    m_tableView.setModel(&m_model);
    m_listView.setModel(&m_model);
    m_treeView.setModel(&m_model);
}

void Widget::initModel()
{
    QStandardItem* root = m_model.invisibleRootItem();
    QStandardItem* itemA = new QStandardItem();
    QStandardItem* itemB = new QStandardItem();
    QStandardItem* itemC = new QStandardItem();
    QStandardItem* itemChild = new QStandardItem();

    itemA->setData("A", Qt::DisplayRole);
    itemA->setData("Tip A", Qt::ToolTipRole);
    itemA->setData("Help A", Qt::WhatsThisRole);

    itemB->setData("B", Qt::DisplayRole);
    itemB->setData("Tip B", Qt::ToolTipRole);

    itemC->setData("C", Qt::DisplayRole);
    itemC->setData("Tip C", Qt::ToolTipRole);
    itemC->setData("Help C", Qt::WhatsThisRole);

    itemChild->setData("Child", Qt::DisplayRole);
    itemChild->setData("Tip Child", Qt::ToolTipRole);
    itemChild->setData("Help Child", Qt::WhatsThisRole);

    itemC->setChild(0, 0, itemChild);

    root->setChild(0, 0, itemA);
    root->setChild(0, 1, itemB);
    root->setChild(1, 0, itemC);
}

void Widget::initView()
{
    m_tableView.setParent(this);
    m_tableView.move(10, 10);
    m_tableView.resize(300, 100);

    m_listView.setParent(this);
    m_listView.move(10, 120);
    m_listView.resize(300, 100);

    m_treeView.setParent(this);
    m_treeView.move(10, 230);
    m_treeView.resize(300, 100);
}

Widget::~Widget()
{
    
}
