#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPlainTextEdit>
#include "UpdateThread.h"

class Widget : public QWidget
{
    Q_OBJECT

    UpdateThread m_thread;
    QPlainTextEdit textEdit;
protected slots:
    void appendText(QString text);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
