#ifndef SYNCTHREAD_H
#define SYNCTHREAD_H

#include <QThread>

class SyncThread : public QThread
{
    Q_OBJECT

protected:
    void run();

public:
    explicit SyncThread(QObject *parent = 0);
    ~SyncThread();
};

#endif // SYNCTHREAD_H
