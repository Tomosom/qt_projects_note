#include "QMyPushButton.h"
#include <QMouseEvent>

QMyPushButton::QMyPushButton(QWidget* parent, QButtonListener* listener) : QPushButton(parent)
{
    m_listener = listener;
}

void QMyPushButton::mouseReleaseEvent(QMouseEvent *e) /* 调用重写的函数 */
{
    if( m_listener != NULL )
    {
        m_listener(this, e); /* 调用函数指针 */

        /* 更新界面相关的逻辑, 若无下面语句,按钮按下去后不能弹起来 */
        e->accept(); /* 标记当前的事件已经被处理了 */
        setDown(false); /* 处理UI的更新, false : 使按钮弹起来 */
    }
    else
    {
        /* 默认的QPushButton的行为 */
        QPushButton::mouseReleaseEvent(e);
    }
}

