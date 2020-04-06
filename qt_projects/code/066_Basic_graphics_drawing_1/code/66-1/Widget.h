#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include <QPushButton>
#include <QPoint>
#include <QList>

class Widget : public QWidget
{
    Q_OBJECT

    enum
    {
        LINE,
        RECT,
        ELLIPSE
    };

    struct DrawParam
    {
        int type;
        Qt::PenStyle pen;
        QPoint begin;
        QPoint end;
    };
    
    QPushButton m_testBtn;
    QList<DrawParam> m_list;


protected slots:
    void onTestBtnClicked();
protected:
    void paintEvent(QPaintEvent *);
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
