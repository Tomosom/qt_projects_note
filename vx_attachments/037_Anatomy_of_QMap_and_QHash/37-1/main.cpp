#include <QtCore/QCoreApplication>
#include <QDebug>
#include <QMap>
#include <QMapIterator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> map;

    map.insert("key 2", 2);
    map.insert("key 1", 1);
    map.insert("key 0", 0);

    /* 打印键 */
    QList<QString> kList = map.keys();
    for (int i = 0; i < kList.count(); i++) {
        qDebug() << kList[i]; /* 有自动排序 */
    }

    /* 打印值 */
    QList<int> vList = map.values();
    for (int i = 0; i < vList.count(); i++) {
        qDebug() << vList[i];
    }

    /* 打印键值对 */
    QMapIterator<QString, int> it(map); /* 指向map对象第一个元素之前的为位置 */
    while (it.hasNext()) {
        it.next();
        qDebug() << it.key() << " : " << it.value();
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
    */

    return a.exec();
}
