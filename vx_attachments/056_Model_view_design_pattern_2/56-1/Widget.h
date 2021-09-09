#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPlainTextEdit>
#include <QFileSystemModel>

class Widget : public QWidget
{
    Q_OBJECT
    
    QPlainTextEdit m_edit;
    QFileSystemModel m_fsm;
protected slots:
    void onDirectoryLoaded(const QString& path);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
