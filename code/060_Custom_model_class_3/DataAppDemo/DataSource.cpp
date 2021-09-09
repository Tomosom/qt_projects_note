#include "DataSource.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

DataSource::DataSource(QObject *parent) : QObject(parent)
{
}

bool DataSource::setDataPath(QString path)
{
    bool ret = true;
    QFile file(path);

    if( file.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        QTextStream in(&file);

        while( !in.atEnd() )
        {
            ScoreInfo info;

            if( parse(in.readLine(), info) )
            {
                m_data.append(info);
            }
        }

        file.close();
    }
    else
    {
        ret = false;
    }

    return ret;
}

bool DataSource::parse(QString line, ScoreInfo& info)
{
    bool ret = true;
    QStringList list = line.split(",", QString::SkipEmptyParts);

    if( list.count() == 3 )
    {
        QString id = list[0].trimmed();
        QString name = list[1].trimmed();
        QString score = list[2].trimmed();
        int value = score.toInt(&ret);

        if( ret && (0 <= value) && (value <=150) )
        {
            info = ScoreInfo(id, name, value);
        }
        else
        {
            ret = false;
        }
    }
    else
    {
        ret = false;
    }

    return ret;
}

QList<ScoreInfo> DataSource::fetchData()
{
    QList<ScoreInfo> ret = m_data;

    m_data.clear();

    return ret;
}

int DataSource::count()
{
    return m_data.count();
}


