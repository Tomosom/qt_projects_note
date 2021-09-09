#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QPixmap>

class Widget : public QWidget
{
    Q_OBJECT

    QPushButton m_loadBtn;
    QPushButton m_grabBtn;
    QPixmap m_pmap;

private slots:
    void onLoadBtnClicked();
    void onGrabBtnClicked();
protected:
    void paintEvent(QPaintEvent *);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
