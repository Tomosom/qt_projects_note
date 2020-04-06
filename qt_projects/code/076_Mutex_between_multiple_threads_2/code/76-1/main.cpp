#include <QtCore/QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QDebug>

QMutex g_mutex_1;
QMutex g_mutex_2;

class ThreadA : public QThread
{
protected:
    void run()
    {
        while( true )
        {
            g_mutex_1.lock();

            qDebug() << objectName() << "get m1";

            g_mutex_2.lock();

            qDebug() << objectName() << "get m2";

            qDebug() << objectName() << "do work ...";

            g_mutex_2.unlock();
            g_mutex_1.unlock();

            sleep(1);
        }
    }
};

class ThreadB : public QThread
{
protected:
    void run()
    {
        while( true )
        {
            g_mutex_1.lock();

            qDebug() << objectName() << "get m2";

            g_mutex_2.lock();

            qDebug() << objectName() << "get m1";

            qDebug() << objectName() << "do work ...";

            g_mutex_2.unlock();
            g_mutex_1.unlock();

            sleep(1);
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadA ta;
    ThreadB tb;

    ta.setObjectName("ta");
    tb.setObjectName("tb");

    ta.start();
    tb.start();
    
    return a.exec();
}
