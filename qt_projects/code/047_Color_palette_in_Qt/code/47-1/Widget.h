#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class Widget : public QWidget
{
    Q_OBJECT
    
    QPushButton m_button;
    QLineEdit m_edit;
    QLabel m_label;
protected slots:
    void onButtonClicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
