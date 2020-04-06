#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>
#include "MyThread.h"
#include "SyncThread.h"
#include "AsyncThread.h"

void test()
{
    MyThread t;

    t.start();
}

void sync_thread()
{
    SyncThread st;

    st.start();
}

void async_thread()
{
    AsyncThread* at = AsyncThread::NewInstance();

    at->start();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThread();

    // test();
    // sync_thread();
    async_thread();
    
    return a.exec();
}
