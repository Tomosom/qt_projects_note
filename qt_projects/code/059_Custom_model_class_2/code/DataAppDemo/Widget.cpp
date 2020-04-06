#include "Widget.h"
#include "ScoreInfo.h"
#include "DataSource.h"
#include "ScoreInfoModel.h"
#include <QDebug>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    DataSource ds;
    ScoreInfoModel sim;

    if( ds.setDataPath("C:/Users/hp/Desktop/test.txt") )
    {
        qDebug() << "item cout: " << ds.count();

        QList<ScoreInfo> list = ds.fetchData();

        for(int i=0; i<list.count(); i++)
        {
            qDebug() << list[i].id();
            qDebug() << list[i].name();
            qDebug() << list[i].score();
            qDebug() << endl;

            sim.add(list[i]);
        }

        qDebug() << "test model:" << endl;

        for(int i=0; i<sim.count(); i++)
        {
            ScoreInfo info = sim.getItem(i);

            qDebug() << info.id();
            qDebug() << info.name();
            qDebug() << info.score();
            qDebug() << endl;
        }

        qDebug() << endl;
    }
    else
    {
        qDebug() << "data source read error";
    }
}

Widget::~Widget()
{
    
}
