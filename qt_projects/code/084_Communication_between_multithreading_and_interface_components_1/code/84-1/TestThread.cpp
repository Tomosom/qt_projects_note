#include "TestThread.h"
#include <QWidget>

TestThread::TestThread(QObject *parent) :
    QThread(parent)
{
}

void TestThread::run()
{
    /* It is ERROR to create GUI elements in SUB THREAD */
    QWidget w;

    w.show();

    exec();
}
