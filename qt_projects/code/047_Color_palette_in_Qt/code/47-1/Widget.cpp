#include "Widget.h"
#include <QPalette>

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_button(this), m_edit(this), m_label(this)
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
    p.setColor(QPalette::Inactive, QPalette::ButtonText, Qt::red);

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
    p.setColor(QPalette::Inactive, QPalette::WindowText, Qt::green);

    m_label.setPalette(p);
}

Widget::~Widget()
{
    
}
