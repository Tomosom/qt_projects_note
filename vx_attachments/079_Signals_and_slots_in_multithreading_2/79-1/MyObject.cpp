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

void MyObject::testSlot()
{
    qDebug() << "void MyObject::testSlot() tid = " << QThread::currentThreadId();
}

