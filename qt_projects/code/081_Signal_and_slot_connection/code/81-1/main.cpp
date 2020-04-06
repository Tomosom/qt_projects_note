#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QThread>
#include "TestThread.h"
#include "MyObject.h"

void direct_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::DirectConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

void queued_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::QueuedConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

void blocking_queued_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::BlockingQueuedConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

void auto_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()));

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

void unique_connection()
{
    static TestThread t;
    static MyObject m;

    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::UniqueConnection);
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()), Qt::UniqueConnection);

    t.start();

    t.wait(5 * 1000);

    t.quit();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    // direct_connection();
    // queued_connection();
    // blocking_queued_connection();
    // auto_connection();
    // unique_connection();

    return a.exec();
}
