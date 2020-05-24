#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QFile file("C:/Users/hp/Desktop/test.hex");
    QFile file("test.hex");

    /* 没有加 QIODevice::Text 表示以字节流的方式打开文件 */
    if( file.open(QIODevice::WriteOnly) )
    {
        QString dt = "D.T.Software";
        double value = 3.14;

        /* 使用QFile进行数据或文本的读写是可行的,此处为不方便的地方-类型转换 */
        file.write(dt.toStdString().c_str()); // 将QString数据转为直接的二进制数据
        file.write(reinterpret_cast<char*>(&value), sizeof(value)); // 将其转换为字节类型的数据

        file.close();
    }

    if( file.open(QIODevice::ReadOnly) )
    {
        QString dt = "";
        double value = 0;

        dt = QString(file.read(12)); /* "D.T.Software" */
        file.read(reinterpret_cast<char*>(&value), sizeof(value));

        file.close();

        qDebug() << dt;
        qDebug() << value;
    }
    
    return a.exec();
}
