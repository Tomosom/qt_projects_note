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

    return QLineEdit::event(e); /* 调用父类的事件处理函数 */
    //return 0;
}

void MyLineEdit::keyPressEvent(QKeyEvent *e)
{
    qDebug() << "MyLineEdit::keyPressEvent";
    QLineEdit::keyPressEvent(e); /* 调用父类的事件处理函数，里边会设置当前事件已被处理 */

    // 告诉QT平台当前的事件没有处理，会自动给父组件处理
    e->ignore();
}
