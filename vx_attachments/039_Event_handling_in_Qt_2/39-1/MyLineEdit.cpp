#include "MyLineEdit.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

MyLineEdit::MyLineEdit(QWidget *parent) :
    QLineEdit(parent)
{
}

bool MyLineEdit::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress) {
        qDebug() << "MyLineEdit::event";
    }

    return QLineEdit::event(e);
}

void MyLineEdit::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "MyLineEdit::keyPressEvent";
    QLineEdit::keyPressEvent(e);

    // e->ignore();
}
