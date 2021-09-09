#ifndef _QMYPUSHBUTTON_H_
#define _QMYPUSHBUTTON_H_

#include <QPushButton>

typedef void (QButtonListener)(QObject*, QMouseEvent*);

class QMyPushButton : public QPushButton
{
    Q_OBJECT
protected:
    QButtonListener* m_listener;

    void mouseReleaseEvent(QMouseEvent *e);
public:
    explicit QMyPushButton(QWidget* parent = 0, QButtonListener* listener = 0);
    
signals:
    
public slots:
    
};

#endif // _QMYPUSHBUTTON_H_
