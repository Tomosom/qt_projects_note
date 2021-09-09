#include <QtCore/QCoreApplication>
#include <QBuffer>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>

void write_buffer(int type, QBuffer& buffer)
{
    if( buffer.open(QIODevice::WriteOnly) )
    {
        QDataStream out(&buffer);

        out << type;

        if( type == 0 )
        {
            out << QString("D.T.Software");
            out << QString("3.1415");
        }
        else if( type == 1 )
        {
            out << 3;
            out << 1415;
        }
        else if( type == 2 )
        {
            out << 3.1415;
        }

        buffer.close();
    }
}

void read_buffer(QBuffer& buffer)
{
    if( buffer.open(QIODevice::ReadOnly) )
    {
        int type = -1;
        QDataStream in(&buffer);

        in >> type;

        if( type == 0 )
        {
            QString dt = "";
            QString pi = "";

            in >> dt;
            in >> pi;

            qDebug() << dt;
            qDebug() << pi;
        }
        else if( type == 1 )
        {
            int a = 0;
            int b = 0;

            in >> a;
            in >> b;

            qDebug() << a;
            qDebug() << b;
        }
        else if( type == 2 )
        {
            double pi = 0;

            in >> pi;

            qDebug() << pi;
        }

        buffer.close();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QByteArray array;
    QBuffer buffer(&array);

    write_buffer(2, buffer);
    read_buffer(buffer);
    
    return a.exec();
}
