#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT

protected:
    int i;

    void run();
public:
    explicit MyThread(QObject *parent = 0);
    
};

#endif // MYTHREAD_H
