
#include <QDebug>

void Sample_1()
{
    QString s = "add";

    s.append(" ");    // "add "
    s.append("Qt");   // "add Qt"
    s.prepend(" ");   // " add Qt"
    s.prepend("C++"); // "C++ add Qt"

    qDebug() << s;

    s.replace("add", "&"); // "C++ & Qt"

    qDebug() << s;
}

void Sample_2()
{
    QString s = "";
    int index = 0;

    s.sprintf("%d. I'm %s, thank you!", 1, "Tom"); // "1. I'm Tom, thank you!"

    qDebug() << s;

    index = s.indexOf(",");

    s = s.mid(0, index);   // "1. I'm Tom"

    qDebug() << s;

    index = s.indexOf(".");

    s = s.mid(index + 1, s.length()); // " I'm Tom"
    s = s.trimmed();                  // "I'm Tom"

    qDebug() << s;

    index = s.indexOf(" ");

    s = s.mid(index + 1, s.length()); // "Tom"

    qDebug() << s;
}

/* 使用QT的比较操作符重载直接比较 */
void Sample_3(QString* a, int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if( a[j] < a[i] )
            {
                QString tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main()
{
    qDebug() << "Sample_1:";

    Sample_1();

    qDebug() << endl;
    qDebug() << "Sample_2:";

    Sample_2();

    qDebug() << endl;
    qDebug() << "Sample_3:";

    QString company[5] =
    {
        QString("Oracle"),
        QString("Borland"),
        QString("Microsoft"),
        QString("IBM"),
        QString("Tom")
    };

    Sample_3(company, 5);

    for(int i=0; i<5; i++)
    {
        qDebug() << company[i]; // Borland IBM Microsoft Oracle Tom
    }

    return 0;
}
