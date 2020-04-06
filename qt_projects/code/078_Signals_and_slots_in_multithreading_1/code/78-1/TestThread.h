#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QThread>

class TestThread : public QThread
{
    Q_OBJECT

protected:
    void run();
public:
    explicit TestThread(QObject *parent = 0);
    
signals:
    void testSignal();
protected slots:
    void testSlot();
};

#endif // TESTTHREAD_H
