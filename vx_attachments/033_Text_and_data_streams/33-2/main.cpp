#include <QtCore/QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QDebug>

void text_stream_test(QString f)
{
    QFile file(f);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        out << QString("D.T.Software") << endl;
        out << QString("Result: ") << endl;
        out << 5 << '*' << 6 << '=' << 5 * 6 << endl;

        file.close();
    }

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while (!in.atEnd()) {
            QString line = in.readLine(); /* 以行为单位读取 */
            qDebug() << line;
        }

        file.close();
    }
}

void data_stream_test(QString f)
{
    QFile file(f);

    if (file.open(QIODevice::WriteOnly)) { /* 此处没有 QIODevice::Text */
        QDataStream out(&file);

        out.setVersion(QDataStream::Qt_4_7); /* 解决不同Qt版本的数据流文件格式可能不同的问题 */

        out << QString("D.T.Software");
        out << QString("Result: ");
        out << 3.14;

        file.close();
    }

    if (file.open(QIODevice::ReadOnly)) { /* 此处没有 QIODevice::Text */
        QDataStream in(&file);
        QString dt = "";
        QString result = "";
        double value = 0;

        in.setVersion(QDataStream::Qt_4_7); /* 解决不同Qt版本的数据流文件格式可能不同的问题 */

        in >> dt;
        in >> result;
        in >> value;

        qDebug() << dt;
        qDebug() << result;
        qDebug() << value;

        file.close();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    text_stream_test("text.txt"); /* 当前目录路径 */
    data_stream_test("data.dat"); /* 当前目录路径 */

    return a.exec();
}
