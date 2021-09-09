#include "TestThread.h"
#include <QDebug>

TestThread::TestThread(QObject *parent) :
    QThread(parent)
{

}

void TestThread::run()
{
    qDebug() << "void TestThread::run() -- begin tid = " << currentThreadId();

    for(int i=0; i<3; i++)
    {
        qDebug() << "void TestThread::run() i = " << i;

        sleep(1);
    }

    emit testSignal();

    exec();

    qDebug() << "void TestThread::run() -- end";
}


