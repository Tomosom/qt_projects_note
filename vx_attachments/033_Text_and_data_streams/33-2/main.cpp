#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>

void text_stream_test(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QTextStream out(&file);

        out << QString("D.T.Software") << endl;
        out << QString("Result: ") << endl;
        out << 5 << '*' << 6 << '=' << 5 * 6 << endl;

        file.close();
    }

    if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QTextStream in(&file);

        while( !in.atEnd() )
        {
            QString line = in.readLine();

            qDebug() << line;
        }

        file.close();
    }
}

void data_stream_test(QString f)
{
    QFile file(f);

    if( file.open(QIODevice::WriteOnly) ) /* �˴�û�� QIODevice::Text */
    {
        QDataStream out(&file);

        /* �����ͬQt�汾���������ļ���ʽ���ܲ�ͬ������ */
        out.setVersion(QDataStream::Qt_4_7);

        out << QString("D.T.Software");
        out << QString("Result: ");
        out << 3.14;

        file.close();
    }

    if( file.open(QIODevice::ReadOnly) ) /* �˴�û�� QIODevice::Text */
    {
        QDataStream in(&file);
        QString dt = "";
        QString result = "";
        double value = 0;

        /* �����ͬQt�汾���������ļ���ʽ���ܲ�ͬ������ */
        in.setVersion(QDataStream::Qt_4_7);

        in >> dt;
        in >> result;
        in >> value;

        file.close();

        qDebug() << dt;
        qDebug() << result;
        qDebug() << value;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //text_stream_test("C:/Users/hp/Desktop/text.txt");
    //data_stream_test("C:/Users/hp/Desktop/data.dat");

    text_stream_test("text.txt");
    data_stream_test("data.dat");

    return a.exec();
}
