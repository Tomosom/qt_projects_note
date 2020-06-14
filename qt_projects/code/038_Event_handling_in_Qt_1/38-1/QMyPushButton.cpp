#include "QMyPushButton.h"
#include <QMouseEvent>

QMyPushButton::QMyPushButton(QWidget* parent, QButtonListener* listener) : QPushButton(parent)
{
    m_listener = listener;
}

void QMyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if( m_listener != NULL )
    {
        m_listener(this, e);

        e->accept();

        setDown(false);
    }
    else
    {
        QPushButton::mouseReleaseEvent(e);
    }
}

