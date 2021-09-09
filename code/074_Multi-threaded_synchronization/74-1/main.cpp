#include <QtCore/QCoreApplication>
#include <QThread>
#include <QDebug>

/*
  sum(n) => 1 + 2 + 3 + ... + n

  sum(1000) => ?

            [1, 1000] =  [1, 300] [301, 600] [601, 1000]
  */

class Calculator : public QThread
{
protected:
    int m_begin;
    int m_end;
    int m_result;

    void run()
    {
        qDebug() << objectName() << ": run() begin";

        for(int i=m_begin; i<=m_end; i++)
        {
            m_result += i;

            msleep(10);
        }

        qDebug() << objectName() << ": run() end";
    }
public:
    Calculator(int begin, int end)
    {
        m_begin = begin;
        m_end = end;
        m_result = 0;
    }

    void work()
    {
        run();
    }

    int result()
    {
        return m_result;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main begin";

    Calculator cal1(1, 300);
    Calculator cal2(301, 600);
    Calculator cal3(601, 1000);

    cal1.setObjectName("cal1");
    cal2.setObjectName("cal2");
    cal3.setObjectName("cal3");

    // cal1.work();
    // cal2.work();
    // cal3.work();

    cal1.start();
    cal2.start();
    cal3.start();

    cal1.wait();
    cal2.wait();
    cal3.wait();

    int result = cal1.result() + cal2.result() + cal3.result();

    qDebug() << "result = " << result;

    qDebug() << "main end";
    
    return a.exec();
}
