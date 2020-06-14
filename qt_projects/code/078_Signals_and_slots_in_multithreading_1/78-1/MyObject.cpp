#include "MyObject.h"
#include <QThread>
#include <QDebug>

MyObject::MyObject(QObject *parent) :
    QObject(parent)
{
}

void MyObject::getStarted()
{
    qDebug() << "void MyObject::getStarted() tid = " << QThread::currentThreadId();
}

void MyObject::getFinished()
{
    qDebug() << "void MyObject::getFinished() tid = " << QThread::currentThreadId();
}

void MyObject::getTerminated()
{
    qDebug() << "void MyObject::getTerminated() tid = " << QThread::currentThreadId();
}
