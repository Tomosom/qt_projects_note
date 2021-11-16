#include <QtCore/QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>

void test_dir()
{
    //const char* PATH = "C:/Users/hp/Desktop/QDir";
    const char* PATH = "./QDir";
    QDir dir;

    if( !dir.exists(PATH) )
    {
        dir.mkdir(PATH);
    }

    if( dir.exists(PATH) )
    {
        dir.cd(PATH);

        QStringList list = dir.entryList();

        for(int i=0; i<list.count(); i++)
        {
            qDebug() << list[i];
        }
    }
}

#define ERR 1

unsigned int calculate_size(QString path)
{
    QFileInfo info(path);
    unsigned int ret = 0;

    if( info.isFile() )
    {
        ret = info.size();
    }
    else if( info.isDir() )
    {
        QDir dir(path);

#if ERR
        QStringList list = dir.entryList();
#else
        QFileInfoList list = dir.entryInfoList();
#endif

        for(int i=0; i<list.count(); i++)
        {
#if ERR
            if( (list[i] != ".") && (list[i] != "..") )
#else
            if( (list[i].fileName() != ".") && (list[i].fileName() != "..") )
#endif
            {
#if ERR
                qDebug() << list[i]; // 仅仅取到的是条目, 不是绝对路径
                ret += calculate_size(list[i]);
#else
                qDebug() << list[i].absoluteFilePath();
                ret += calculate_size(list[i].absoluteFilePath());
#endif
            }
        }
    }

    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //test_dir();

    //qDebug() << calculate_size("C:/Users/hp/Desktop/QDir");
    qDebug() << calculate_size("./QDir");
    return a.exec();
}
