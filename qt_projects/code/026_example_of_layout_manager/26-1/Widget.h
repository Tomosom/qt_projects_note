#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <QtGui/QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QStackedLayout>

class Widget : public QWidget
{
    Q_OBJECT

private:
    QPushButton preBtn;
    QPushButton nextBtn;
    QLabel fLbl1;
    QLabel fLbl2;
    QLabel fLbl3;
    QLabel fLbl4;
    QLineEdit sLineEdit;
    QPushButton tPushBtn1;
    QPushButton tPushBtn2;
    QStackedLayout sLayout;

    void initControl();
    QWidget* get1stPage();
    QWidget* get2ndPage();
    QWidget* get3rdPage();
private slots:
    void onPreBtnClicked();
    void onNextBtnClicked();
public:
    Widget(QWidget* parent = 0);
    ~Widget();
};

#endif // _WIDGET_H_
