#ifndef RXCLASS_H
#define RXCLASS_H

#include <QObject>
#include <QDebug>

class RxClass : public QObject
{
    Q_OBJECT
public:

    
protected slots:
    void mySlot(int v)
    {
        qDebug() << "void mySlot(int v)";
        qDebug() << "Sender: " << sender()->objectName();
        qDebug() << "Receiver: " << this->objectName();
        qDebug() << "Value: " << v;
        qDebug() << endl;
    }
};

#endif // RXCLASS_H
