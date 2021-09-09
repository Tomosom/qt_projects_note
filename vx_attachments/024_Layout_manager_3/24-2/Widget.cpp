#include "Widget.h"
#include <QLineEdit>
#include <QFormLayout>

Widget::Widget(QWidget *parent) : QWidget(parent, Qt::WindowCloseButtonHint)
{
    QLineEdit* nameEdit = new QLineEdit();
    QLineEdit* mailEdit = new QLineEdit();
    QLineEdit* addrEdit = new QLineEdit();
    QFormLayout* layout = new QFormLayout();

    layout->addRow("Name:", nameEdit);
    layout->addRow("Email:", mailEdit);
    //layout->addRow("Address:", addrEdit);
    layout->addRow("Address----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:", addrEdit);
    //layout->setRowWrapPolicy(QFormLayout::WrapAllRows);
    layout->setRowWrapPolicy(QFormLayout::WrapLongRows); // 针对嵌入式小屏,文字太长时换行
    layout->setLabelAlignment(Qt::AlignRight);
    layout->setSpacing(10);

    setLayout(layout);
    setWindowTitle("FTP");
}

Widget::~Widget()
{
    
}
