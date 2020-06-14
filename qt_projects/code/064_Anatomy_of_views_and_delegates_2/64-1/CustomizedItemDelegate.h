#ifndef CUSTOMIZEDITEMDELEGATE_H
#define CUSTOMIZEDITEMDELEGATE_H

#include <QItemDelegate>

class CustomizedItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit CustomizedItemDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};

#endif // CUSTOMIZEDITEMDELEGATE_H
