#ifndef CUSTOMIZEDITEMDELEGATE_H
#define CUSTOMIZEDITEMDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>

class CustomizedItemDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit CustomizedItemDelegate(QObject *parent = 0);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};

#endif // CUSTOMIZEDITEMDELEGATE_H
