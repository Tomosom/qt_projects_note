#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QThread>
#include "FileWriter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "main() tid = " << QThread::currentThreadId();

    FileWriter writer("C:/Users/hp/Desktop/test.txt");

    if( writer.open() )
    {
        writer.write("D.T.Software\r\n");
        writer.write("中文测试\r\n");
        writer.write("狄泰软件\r\n");
        writer.close();
    }

    return a.exec();
}
