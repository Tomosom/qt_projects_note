#include "Widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    initControl();
}

void Widget::initControl()
{
    QVBoxLayout* vLayout = new QVBoxLayout();
    QHBoxLayout* hLayout = new QHBoxLayout();

    preBtn.setText("Pre Page");
    preBtn.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    preBtn.setMinimumSize(160, 30);

    nextBtn.setText("Next Page");
    nextBtn.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    nextBtn.setMinimumSize(160, 30);

    connect(&preBtn, SIGNAL(clicked()), this, SLOT(onPreBtnClicked()));
    connect(&nextBtn, SIGNAL(clicked()), this, SLOT(onNextBtnClicked()));

    hLayout->addWidget(&preBtn);
    hLayout->addWidget(&nextBtn);

    sLayout.addWidget(get1stPage());
    sLayout.addWidget(get2ndPage());
    sLayout.addWidget(get3rdPage());

    vLayout->addLayout(&sLayout);
    vLayout->addLayout(hLayout);

    setLayout(vLayout);
}

QWidget* Widget::get1stPage()
{
    QWidget* ret = new QWidget();
    QGridLayout* layout = new QGridLayout();

    fLbl1.setText("This");
    fLbl2.setText("is");
    fLbl3.setText("1st");
    fLbl4.setText("page");

    layout->addWidget(&fLbl1, 0, 0);
    layout->addWidget(&fLbl2, 0, 1);
    layout->addWidget(&fLbl3, 1, 0);
    layout->addWidget(&fLbl4, 1, 1);

    qDebug() << ret;
    qDebug() << fLbl1.parent();
    qDebug() << fLbl2.parent();
    qDebug() << fLbl3.parent();
    qDebug() << fLbl4.parent();

    ret->setLayout(layout); // 父子关系在这条语句决定

    qDebug() << ret;
    qDebug() << fLbl1.parent();
    qDebug() << fLbl2.parent();
    qDebug() << fLbl3.parent();
    qDebug() << fLbl4.parent();
    return ret;
}

QWidget* Widget::get2ndPage()
{
    QWidget* ret = new QWidget();
    QFormLayout* layout = new QFormLayout();

    sLineEdit.setText("This is 2rd page");

    layout->addRow("Hint:", &sLineEdit);

    ret->setLayout(layout);

    return ret;
}

QWidget* Widget::get3rdPage()
{
    QWidget* ret = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();

    tPushBtn1.setText("This is");
    tPushBtn2.setText("3rd page");

    layout->addWidget(&tPushBtn1);
    layout->addWidget(&tPushBtn2);

    ret->setLayout(layout);

    return ret;
}

void Widget::onPreBtnClicked()
{
    int index = ((sLayout.currentIndex() - 1) + 3) % 3;

    sLayout.setCurrentIndex(index);
}

void Widget::onNextBtnClicked()
{
    int index = (sLayout.currentIndex() + 1) % 3;

    sLayout.setCurrentIndex(index);
}

Widget::~Widget()
{
    
}
