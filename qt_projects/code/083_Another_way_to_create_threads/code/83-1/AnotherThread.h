#ifndef ANOTHERTHREAD_H
#define ANOTHERTHREAD_H

#include <QObject>
#include <QThread>

class AnotherThread : public QObject
{
    Q_OBJECT

    QThread m_thread;
protected slots:
    void tmain();
public:
    explicit AnotherThread(QObject *parent = 0);
    void start();
    void terminate();
    void exit(int c);
    ~AnotherThread();
    
};

#endif // ANOTHERTHREAD_H
