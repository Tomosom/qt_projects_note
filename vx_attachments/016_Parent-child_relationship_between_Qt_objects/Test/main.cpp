#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
//#include <QtCore>
#include <QDebug>
#include <QPushButton>

class MObj : public QObject
{
    QString m_name;
public:
    MObj(const QString& name)
    {
        m_name = name;

        qDebug() << "Constructor: " << m_name;
    }

    ~MObj()
    {
        qDebug() << "Destructor: " << m_name;
    }
};

/* 通过QObject对象接口手动添加父子关系 */
void fcTest()
{
    QObject* p = new QObject();
    QObject* c1 = new QObject();
    QObject* c2 = new QObject();

    c1->setParent(p);
    c2->setParent(p);

    qDebug() << "c1: " << c1;
    qDebug() << "c2: " << c2;

    const QObjectList& list = p->children();

    for(int i=0; i<list.length(); i++)
    {
        qDebug() << list[i];
    }

    qDebug() << "p: " << p;

    qDebug() << "c1 parent: " << c1->parent();
    qDebug() << "c2 parent: " << c2->parent();
}

void delTest()
{
    MObj* obj1 = new MObj("obj1");
    MObj* obj2 = new MObj("obj2");
    MObj* obj3 = new MObj("obj3");
    MObj* obj4 = new MObj("obj4");

    obj2->setParent(obj1);
    obj3->setParent(obj1);
    obj4->setParent(obj3);

    delete obj3;
    //delete obj4; // 若添加此句,代码会因重复delete而停在此处

    const QObjectList& list = obj1->children();

    qDebug() << "obj2: " << obj2;

    for(int i=0; i<list.length(); i++)
    {
        qDebug() << list[i];
    }

}

/* 类成员是否是其children */
void class_new_children()
{

    QPushButton *pb = new QPushButton;

    QPushButton *pb1 = new QPushButton(pb); // 此处会 pb1->setParent(pb);

    qDebug() << "parent : " << pb;
    qDebug() << "child->parent : " << pb1->parent();

    delete pb;
    //delete pb1; // 若添加此句,代码会因重复delete而停在此处,不会打印下面的语句

    qDebug() << "over";
}


int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);

    //fcTest();
    //delTest();

    class_new_children();

    return a.exec();
}
