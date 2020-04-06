#include "Widget.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDebug>
#include <QList>
#include <QUrl>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    setAcceptDrops(true);
}

void Widget::dragEnterEvent(QDragEnterEvent* e)
{
    if( e->mimeData()->hasUrls() )
    {
        e->acceptProposedAction();
    }
    else
    {
        e->ignore();
    }
}

void Widget::dropEvent(QDropEvent* e)
{
    if( e->mimeData()->hasUrls() )
    {
        QList<QUrl> list = e->mimeData()->urls();

        for(int i=0; i<list.count(); i++)
        {
            qDebug() << list[i].toLocalFile();
        }
    }
    else
    {
        e->ignore();
    }
}

Widget::~Widget()
{
    
}
