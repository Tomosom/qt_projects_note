#include <QtCore/QCoreApplication>
#include <QVariant>
#include <QPoint>
#include <QDebug>

QVariant func()
{
    QVariant ret;

    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariant v1(1);
    QVariant v2(3.14);
    QVariant v3("520");
    QVariant v4(QPoint(15, 15));
    QVariant v5;

    qDebug() << v1.type();
    qDebug() << v1.typeName();
    qDebug() << v1.toInt();

    qDebug() << endl;

    qDebug() << v2.type();
    qDebug() << v2.typeName();
    qDebug() << v2.toInt();
    qDebug() << v2.toDouble();
    qDebug() << v2.value<double>();

    qDebug() << endl;

    qDebug() << v3.type();
    qDebug() << v3.typeName();
    qDebug() << v3.toInt();
    qDebug() << v3.value<QString>();

    qDebug() << endl;

    bool ok = true;

    qDebug() << v4.type();
    qDebug() << v4.typeName();
    qDebug() << v4.toInt(&ok);
    qDebug() << ok;
    qDebug() << v4.toPoint();

    qDebug() << endl;

    qDebug() << v5.isValid();

    
    return a.exec();
}
