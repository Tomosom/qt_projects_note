#include "MyThread.h"

MyThread::MyThread(QObject *parent) :
    QThread(parent)
{
}

void MyThread::run()
{
    this->i = 1;

    for(int i=0; i<5; i++)
    {
        this->i *= 2;

        sleep(1);
    }
}
