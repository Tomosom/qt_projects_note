#ifndef ASYNCTHREAD_H
#define ASYNCTHREAD_H

#include <QThread>

class AsyncThread : public QThread
{
    Q_OBJECT

protected:
    void run();
    explicit AsyncThread(QObject *parent = 0);
    ~AsyncThread();

public:
    static AsyncThread* NewInstance(QObject *parent = 0);
    
};

#endif // ASYNCTHREAD_H
