#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QHash>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QHash<QString, int> hash;

    hash.insert("key 2", 2);
    hash.insert("key 1", 1);
    hash.insert("key 0", 0);

    QList<QString> kList = hash.keys();
    for (int i = 0; i < kList.count(); i++) {
        qDebug() << kList[i];
    }

    QList<int> vList = hash.values();
    for (int i = 0; i < vList.count(); i++) {
        qDebug() << vList[i];
    }

    hash["key 4"] = 4; /* 数组的方式再插入一个键值对 */

    QHash<QString, int>::const_iterator i;
    for (i = hash.constBegin(); i != hash.constEnd(); ++i) {
        qDebug() << i.key() << " : " << i.value();
    }
    
    /*
    "key 0"
    "key 1"
    "key 2"
    0
    1
    2
    "key 0"  :  0
    "key 1"  :  1
    "key 2"  :  2
    "key 4"  :  4
    */

    return a.exec();
}
