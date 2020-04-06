#include "Widget.h"
#include "StringEvent.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    textEdit.setParent(this);
    textEdit.move(20, 20);
    textEdit.resize(200, 150);
    textEdit.setReadOnly(true);

    m_thread.setParent(this);
    m_thread.start();
}

bool Widget::event(QEvent *evt)
{
    bool ret = true;

    if( evt->type() == StringEvent::TYPE )
    {
        StringEvent* se = dynamic_cast<StringEvent*>(evt);

        if( se != NULL )
        {
            textEdit.appendPlainText(se->data());
        }
    }
    else
    {
        ret = QWidget::event(evt);
    }

    return ret;
}

Widget::~Widget()
{
    
}
