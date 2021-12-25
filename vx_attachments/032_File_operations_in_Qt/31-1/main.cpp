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

    if( file.open(QIODevice::WriteOnly | QIODevice::Text) ) { /* 默认是截断方式 */
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
        //QByteArray ba = file.readAll(); /* 全部读取 */
        //QByteArray ba = file.read(4); /* 读取4个字符 */
        QByteArray ba = file.readLine(); /* 读取一行 */
        QString s(ba);

        qDebug() << s;

        file.close();
    }
}

void info(QString f)
{
    QFile file(f);
    QFileInfo info(file);

    qDebug() << "exists       : " << info.exists();
    qDebug() << "isFile       : " << info.isFile();
    qDebug() << "isReadable   : " << info.isReadable();
    qDebug() << "isWritable   : " << info.isWritable();
    qDebug() << "created      : " << info.created();
    qDebug() << "lastRead     : " << info.lastRead();
    qDebug() << "lastModified : " << info.lastModified();
    qDebug() << "path         : " << info.path();
    qDebug() << "fileName     : " << info.fileName();
    qDebug() << "suffix       : " << info.suffix();
    qDebug() << "size         : " << info.size();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /* 当前路径 */
    qDebug() << "currentPath : " << QDir::currentPath();

    write("./test.txt");
    read("./test.txt");
    info("test.txt");

    return a.exec();
}
