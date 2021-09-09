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
    
signals:
    void updateUI(QString text);
    
};

#endif // UPDATETHREAD_H
