#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile file("C:/Users/hp/Desktop/test.hex");

    if( file.open(QIODevice::WriteOnly) )
    {
        QString dt = "D.T.Software";
        double value = 3.14;

        file.write(dt.toStdString().c_str());
        file.write(reinterpret_cast<char*>(&value), sizeof(value));

        file.close();
    }

    if( file.open(QIODevice::ReadOnly) )
    {
        QString dt = "";
        double value = 0;

        dt = QString(file.read(12));
        file.read(reinterpret_cast<char*>(&value), sizeof(value));

        file.close();

        qDebug() << dt;
        qDebug() << value;
    }
    
    return a.exec();
}
