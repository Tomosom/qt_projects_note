#include <QtCore/QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QDebug>

static QMutex g_mutex;
static QString g_store;

class Producer : public QThread
{
protected:
    void run()
    {
        int count = 0;

        while(true)
        {
            g_mutex.lock();

            g_store.append(QString::number((count++) % 10));

            qDebug() << objectName() << " : " + g_store;

            g_mutex.unlock();

            msleep(1);
        }
    }
};

class Customer : public QThread
{
protected:
    void run()
    {
        while( true )
        {
            g_mutex.lock();

            if( g_store != "" )
            {
                g_store.remove(0, 1);

                qDebug() << objectName() << " : " + g_store;
            }

            g_mutex.unlock();

            msleep(1);
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Producer p;
    Customer c;

    p.setObjectName("Producer");
    c.setObjectName("Customer");
    
    p.start();
    c.start();

    return a.exec();
}
