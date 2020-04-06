#include "Widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent, Qt::WindowCloseButtonHint)
{
    QLabel* nameLbl = new QLabel("Name:");
    QLabel* mailLbl = new QLabel("Email:");
    QLabel* addrLbl = new QLabel("Address:");
    QLineEdit* nameEdit = new QLineEdit();
    QLineEdit* mailEdit = new QLineEdit();
    QLineEdit* addrEdit = new QLineEdit();
    QGridLayout* layout = new QGridLayout();

    layout->setSpacing(10);
    layout->addWidget(nameLbl, 0, 0);
    layout->addWidget(nameEdit, 0, 1);
    layout->addWidget(mailLbl, 1, 0);
    layout->addWidget(mailEdit, 1, 1);
    layout->addWidget(addrLbl, 2, 0);
    layout->addWidget(addrEdit,2, 1);
    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 4);

    setLayout(layout);
    setWindowTitle("FTP");
}

Widget::~Widget()
{
    
}
