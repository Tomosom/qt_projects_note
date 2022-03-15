#include "Widget.h"
#include <QPalette>

// c++深度解析
// 类成员对象的声明的顺序 与 初始化列表里边初始化的顺序不一样，会产生警告。
// 不一致可能会造成一些错误。
Widget::Widget(QWidget *parent)
    : QWidget(parent), m_button(this), m_edit(this), m_label(this) // 初始化列表中指定父组件
{
    m_label.move(10, 10);
    m_label.resize(150, 25);
    m_label.setText("Test");

    m_edit.move(10, 45);
    m_edit.resize(150, 25);

    m_button.move(10, 80);
    m_button.resize(150, 25);
    m_button.setText("Test");

    connect(&m_button, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

    QPalette p = m_button.palette();
    p.setColor(QPalette::Active, QPalette::ButtonText, Qt::red);
    /* 对话框拾取焦点时，若没有下面这一句，颜色会不一样。 */
    //p.setColor(QPalette::Inactive, QPalette::ButtonText, Qt::red);
    m_button.setPalette(p);

    p = m_edit.palette();
    p.setColor(QPalette::Inactive, QPalette::Highlight, Qt::blue);
    p.setColor(QPalette::Inactive, QPalette::HighlightedText, Qt::white);
    m_edit.setPalette(p);
}

void Widget::onButtonClicked()
{
    QPalette p = m_label.palette();
    p.setColor(QPalette::Active, QPalette::WindowText, Qt::green);
    //p.setColor(QPalette::Inactive, QPalette::WindowText, Qt::green);
    m_label.setPalette(p);
}

Widget::~Widget()
{
    
}
