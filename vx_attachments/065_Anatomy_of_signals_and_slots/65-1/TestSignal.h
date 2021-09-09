#ifndef TESTSIGNAL_H
#define TESTSIGNAL_H

#include <QObject>

class TestSignal : public QObject
{
    Q_OBJECT

public:
    void send(int i)
    {
        emit testSignal(i);
    }
    
signals:
    void testSignal(int v);
    
};

#endif // TESTSIGNAL_H
