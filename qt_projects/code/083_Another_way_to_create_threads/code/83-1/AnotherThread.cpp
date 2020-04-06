#include "AnotherThread.h"
#include <QDebug>

AnotherThread::AnotherThread(QObject *parent) :
    QObject(parent)
{
    moveToThread(&m_thread);

    connect(&m_thread, SIGNAL(started()), this, SLOT(tmain()));
}

void AnotherThread::tmain()
{
    qDebug() << "void AnotherThread::tmain() tid = " << QThread::currentThreadId();

    for(int i=0; i<10; i++)
    {
        qDebug() << "void AnotherThread::tmain() i = " << i;
    }

    qDebug() << "void AnotherThread::tmain() end";

    m_thread.quit();
}

void AnotherThread::start()
{
    m_thread.start();
}

void AnotherThread::terminate()
{
    m_thread.terminate();
}

void AnotherThread::exit(int c)
{
    m_thread.exit(c);
}

AnotherThread::~AnotherThread()
{
    m_thread.wait();
}
