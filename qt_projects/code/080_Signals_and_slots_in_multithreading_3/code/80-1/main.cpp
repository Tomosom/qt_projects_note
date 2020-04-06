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
    QObject::connect(&t, SIGNAL(testSignal()), &m, SLOT(testSlot()));

    m.moveToThread(&t);
    t.moveToThread(&t);

    t.start();

    t.wait(8 * 1000);

    t.quit();

    return a.exec();
}
