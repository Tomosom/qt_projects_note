#include "QMyPushButton.h"
#include <QMouseEvent>

QMyPushButton::QMyPushButton(QWidget* parent, QButtonListener* listener) : QPushButton(parent)
{
    m_listener = listener;
}

void QMyPushButton::mouseReleaseEvent(QMouseEvent *e) /* ������д�ĺ��� */
{
    if( m_listener != NULL )
    {
        m_listener(this, e); /* ���ú���ָ�� */

        /* ���½�����ص��߼�, �����������,��ť����ȥ���ܵ����� */
        e->accept(); /* ��ǵ�ǰ���¼��Ѿ��������� */
        setDown(false); /* ����UI�ĸ���, false : ʹ��ť������ */
    }
    else
    {
        /* Ĭ�ϵ�QPushButton����Ϊ */
        QPushButton::mouseReleaseEvent(e);
    }
}

