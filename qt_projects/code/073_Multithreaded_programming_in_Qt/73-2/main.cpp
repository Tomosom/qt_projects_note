#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>

class Sample : public QThread
{
protected:
    volatile bool m_toStop;

    void run()
    {
        qDebug() << objectName() << " : begin";

        int* p = new int[10000];

        for(int i=0; !m_toStop && (i<10); i++)
        {
            qDebug() << objectName() << " : " << i;

            p[i] = i * i * i;

            msleep(500);
        }

        delete[] p;

        qDebug() << objectName() << " : end";
   }
public:
    Sample()
    {
        m_toStop = false;
    }

    void stop()
    {
        m_toStop = true;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main begin";

    Sample t;

    t.setObjectName("t");

    t.start();

    for(int i=0; i<100000; i++)
    {
        for(int j=0; j<10000; j++)
        {

        }
    }

    t.stop();
    //t.terminate();

    qDebug() << "main end";
    
    return a.exec();
}
