#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
protected:
    void run()
    {
        qDebug() << objectName() << " : " << "run() begin";

        for(int i=0; i<5; i++)
        {
            qDebug() << objectName() << " : " << i;

            sleep(1);
        }

        qDebug() << objectName() << " : " << "run() end";
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() begin";

    MyThread t;

    t.setObjectName("t");

    t.start();

    MyThread tt;

    tt.setObjectName("tt");

    tt.start();

    for(int i=0; i<100000; i++)
    {
        for(int j=0; j<10000; j++)
        {

        }
    }

    qDebug() << "main() end";
    
    return a.exec();
}
