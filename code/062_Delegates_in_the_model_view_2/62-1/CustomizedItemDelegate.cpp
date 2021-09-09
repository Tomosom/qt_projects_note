#include "CustomizedItemDelegate.h"
#include <QCheckBox>
#include <QComboBox>

CustomizedItemDelegate::CustomizedItemDelegate(QObject *parent) :
    QItemDelegate(parent)
{
    connect(this, SIGNAL(closeEditor(QWidget*)), this, SLOT(onCloseEditor(QWidget*)));
}

QWidget* CustomizedItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QWidget* ret = NULL;

    m_index = index;

    if( index.data().type() == QVariant::Bool )
    {
        QCheckBox* cb = new QCheckBox(parent);

        cb->setText("Check to TRUE");

        ret = cb;
    }
    else if( index.data().type() == QVariant::Char )
    {
        QComboBox* cb = new QComboBox(parent);

        cb->addItem("A");
        cb->addItem("B");
        cb->addItem("C");
        cb->addItem("D");

        ret = cb;
    }
    else
    {
        ret = QItemDelegate::createEditor(parent, option, index);
    }

    return ret;
}

void CustomizedItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

void CustomizedItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if( index.data().type() == QVariant::Bool )
    {
        QCheckBox* cb = dynamic_cast<QCheckBox*>(editor);

        if( cb != NULL )
        {
            cb->setChecked(index.data().toBool());
        }
    }
    else if( index.data().type() == QVariant::Char )
    {
        QComboBox* cb = dynamic_cast<QComboBox*>(editor);

        if( cb != NULL )
        {
            for(int i=0; i<cb->count(); i++)
            {
                if( cb->itemText(i) == index.data().toString() )
                {
                    cb->setCurrentIndex(i);
                    break;
                }
            }
        }
    }
    else
    {
        QItemDelegate::setEditorData(editor, index);
    }
}

void CustomizedItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if( index.data().type() == QVariant::Bool )
    {
        QCheckBox* cb = dynamic_cast<QCheckBox*>(editor);

        if( cb != NULL )
        {
            model->setData(index, cb->isChecked(), Qt::DisplayRole);
        }
    }
    else if( index.data().type() == QVariant::Char )
    {
        QComboBox* cb = dynamic_cast<QComboBox*>(editor);

        if( cb != NULL )
        {
            model->setData(index, cb->currentText().at(0), Qt::DisplayRole);
        }
    }
    else
    {
        QItemDelegate::setModelData(editor, model, index);
    }
}

void CustomizedItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( m_index != index )
    {
        QItemDelegate::paint(painter, option, index);
    }
}

void CustomizedItemDelegate::onCloseEditor(QWidget*)
{
    m_index = QModelIndex();
}
