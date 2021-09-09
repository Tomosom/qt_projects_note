#include "SubStyledItemDelegate.h"
#include <QDebug>

SubStyledItemDelegate::SubStyledItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
    connect(this, SIGNAL(closeEditor(QWidget*)), this, SLOT(onCloseEditor(QWidget*)));
    connect(this, SIGNAL(commitData(QWidget*)), this, SLOT(onCommitData(QWidget*)));
}

QWidget* SubStyledItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    qDebug() << "SubStyledItemDelegate::createEditor";

    return QStyledItemDelegate::createEditor(parent, option, index);
}

void SubStyledItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    qDebug() << "SubStyledItemDelegate::updateEditorGeometry";

    QStyledItemDelegate::updateEditorGeometry(editor, option, index);
}

void SubStyledItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    qDebug() << "SubStyledItemDelegate::setEditorData";

    QStyledItemDelegate::setEditorData(editor, index);
}

void SubStyledItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    qDebug() << "SubStyledItemDelegate::setModelData";

    return QStyledItemDelegate::setModelData(editor, model, index);
}

void SubStyledItemDelegate::onCloseEditor(QWidget* editor)
{
    qDebug() << "SubStyledItemDelegate::onCloseEditor";
}

void SubStyledItemDelegate::onCommitData(QWidget* editor)
{
    qDebug() << "SubStyledItemDelegate::onCommitData";
}
