#include "Widget.h"
#include <QModelIndex>
#include <QDebug>

Widget::Widget(QWidget* parent) : QWidget(parent)
{
    initView();
    initModel();

    m_view.setModel(&m_model);

    m_testBtn.setParent(this);
    m_testBtn.move(10, 120);
    m_testBtn.resize(300, 30);
    m_testBtn.setText("Test");

    connect(&m_testBtn, SIGNAL(clicked()), this, SLOT(onTestBtnClicked()));
}

void Widget::initView()
{
    m_view.setParent(this);
    m_view.move(10, 10);
    m_view.resize(300, 100);
    m_view.setItemDelegate(&m_delegate);
}

void Widget::initModel()
{
    QStandardItem* root = m_model.invisibleRootItem();
    QStandardItem* itemA = new QStandardItem();
    QStandardItem* itemB = new QStandardItem();
    QStandardItem* itemC = new QStandardItem();
    QStandardItem* itemD = new QStandardItem();

    itemA->setData("A", Qt::DisplayRole);
    itemB->setData("B", Qt::DisplayRole);
    itemC->setData("C", Qt::DisplayRole);
    itemD->setData("D", Qt::DisplayRole);

    root->setChild(0, 0, itemA);
    root->setChild(0, 1, itemB);
    root->setChild(1, 0, itemC);
    root->setChild(1, 1, itemD);
}

void Widget::onTestBtnClicked()
{
    qDebug() << "Model Data:";

    for(int i=0; i<m_model.rowCount(); i++)
    {
        qDebug() << "Row: " << i;
        for(int j=0; j<m_model.columnCount(); j++)
        {
            QModelIndex index = m_model.index(i, j, QModelIndex());
            QString text = index.data(Qt::DisplayRole).toString();

            qDebug() << text;
        }
        qDebug() << endl;
    }

    qDebug() << "Current View Delegate: " << m_view.itemDelegate();
}

Widget::~Widget()
{
    
}
