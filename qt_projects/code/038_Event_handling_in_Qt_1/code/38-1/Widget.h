#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include "QMyPushButton.h"

class Widget : public QWidget
{
    Q_OBJECT
    
    QMyPushButton myButton;
protected slots:
    void onMyButtonClicked();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // _WIDGET_H_
