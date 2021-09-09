#include <QtCore/QCoreApplication>
#include <QDebug>
#include "TestSignal.h"
#include "RxClass.h"

void emit_signal()
{
    qDebug() << "emit_signal()" << endl;

    TestSignal t;
    RxClass r;

    t.setObjectName("t");
    r.setObjectName("r");

    QObject::connect(&t, SIGNAL(testSignal(int)), &r, SLOT(mySlot(int)));

    for(int i=0; i<3; i++)
    {
        t.send(i);
    }
}

void one_to_multi()
{
    qDebug() << "one_to_multi()" << endl;

    TestSignal t;
    RxClass r1;
    RxClass r2;

    t.setObjectName("t");
    r1.setObjectName("r1");
    r2.setObjectName("r2");

    QObject::connect(&t, SIGNAL(testSignal(int)), &r1, SLOT(mySlot(int)));
    QObject::connect(&t, SIGNAL(testSignal(int)), &r2, SLOT(mySlot(int)));

    t.send(100);
}

void multi_to_one()
{
    qDebug() << "multi_to_one()" << endl;

    TestSignal t1;
    TestSignal t2;
    RxClass r;

    t1.setObjectName("t1");
    t2.setObjectName("t2");
    r.setObjectName("r");

    QObject::connect(&t1, SIGNAL(testSignal(int)), &r, SLOT(mySlot(int)));
    QObject::connect(&t2, SIGNAL(testSignal(int)), &r, SLOT(mySlot(int)));

    t1.send(101);
    t2.send(102);
}

void signal_to_signal()
{
    qDebug() << "signal_to_signal()" << endl;

    TestSignal t1;
    TestSignal t2;
    RxClass r;

    t1.setObjectName("t1");
    t2.setObjectName("t2");
    r.setObjectName("r");

    QObject::connect(&t1, SIGNAL(testSignal(int)), &t2, SIGNAL(testSignal(int)));
    QObject::connect(&t2, SIGNAL(testSignal(int)), &r, SLOT(mySlot(int)));

    t1.send(101);
    t2.send(102);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // emit_signal();
    // one_to_multi();
    // multi_to_one();
    // signal_to_signal();
    
    return a.exec();
}
