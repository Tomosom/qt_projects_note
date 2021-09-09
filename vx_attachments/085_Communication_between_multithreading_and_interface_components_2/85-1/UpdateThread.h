#ifndef UPDATETHREAD_H
#define UPDATETHREAD_H

#include <QThread>

class UpdateThread : public QThread
{
    Q_OBJECT

protected:
    void run();
public:
    explicit UpdateThread(QObject *parent = 0);
    
};

#endif // UPDATETHREAD_H
