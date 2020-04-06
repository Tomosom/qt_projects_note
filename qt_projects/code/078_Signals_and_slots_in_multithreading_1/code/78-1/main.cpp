#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QThread>
#include "TestThread.h"
#include "MyObject.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    TestThread t;
    MyObject m;

    QObject::connect(&t, SIGNAL(started()), &m, SLOT(getStarted()));
    QObject::connect(&t, SIGNAL(finished()), &m, SLOT(getFinished()));
    QObject::connect(&t, SIGNAL(terminated()), &m, SLOT(getTerminated()));

    t.start();
    
    return a.exec();
}
