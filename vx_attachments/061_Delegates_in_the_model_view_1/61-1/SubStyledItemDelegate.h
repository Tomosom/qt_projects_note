#ifndef SUBSTYLEDITEMDELEGATE_H
#define SUBSTYLEDITEMDELEGATE_H

#include <QStyledItemDelegate>

class SubStyledItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
protected slots:
    void onCloseEditor(QWidget* editor);
    void onCommitData(QWidget* editor);
public:
    explicit SubStyledItemDelegate(QObject* parent = 0);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // SUBSTYLEDITEMDELEGATE_H
