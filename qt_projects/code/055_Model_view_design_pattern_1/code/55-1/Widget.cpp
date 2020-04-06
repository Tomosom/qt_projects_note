#include "Widget.h"
#include <QDir>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_treeView.setParent(this);
    m_treeView.move(10, 10);
    m_treeView.resize(500, 300);

    m_fsModel.setRootPath(QDir::currentPath());

    m_treeView.setModel(&m_fsModel);

    m_treeView.setRootIndex(m_fsModel.index(QDir::currentPath()));
}

Widget::~Widget()
{
    
}
