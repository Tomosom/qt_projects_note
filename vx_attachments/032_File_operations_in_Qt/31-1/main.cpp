#include <QtCore/QCoreApplication>
#include <QFile>
#include <QByteArray>
#include <QDebug>
#include <QFileInfo>
#include <QDateTime>
#include <QDir>

void write(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::WriteOnly | QIODevice::Text) ) /* 默认是截断方式 */
    {
        file.write("D.T.Software\n");
        file.write("Delphi Tang\n");
        file.close();
    }
}

void read(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        //QByteArray ba = file.readAll();     /* 全部读取 */
        //QByteArray ba = file.read(4);         /* 读取4个字符 */
        QByteArray ba = file.readLine();    /* 读取一行 */
        QString s(ba);

        qDebug() << s;

        file.close();
    }
}

void info(QString f)
{
    QFile file(f);
    QFileInfo info(file);

    qDebug() << info.exists();
    qDebug() << info.isFile();
    qDebug() << info.isReadable();
    qDebug() << info.isWritable();
    qDebug() << info.created();
    qDebug() << info.lastRead();
    qDebug() << info.lastModified();
    qDebug() << info.path();
    qDebug() << info.fileName();
    qDebug() << info.suffix();
    qDebug() << info.size();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* 当前路径 */
    //qDebug() << QDir::currentPath();

    //write("C:/Users/hp/Desktop/test.txt");
    //read("C:/Users/hp/Desktop/test.txt");
    //info("C:/Users/hp/Desktop/test.txt");

    write("./test.txt");
    read("./test.txt");
    info("test.txt");

    return a.exec();
}
