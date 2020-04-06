#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QList>
#include "ScoreInfo.h"

class DataSource : public QObject
{
    Q_OBJECT

    QList<ScoreInfo> m_data;
    bool parse(QString line, ScoreInfo& info);
public:
    explicit DataSource(QObject* parent = 0);
    bool setDataPath(QString path);
    QList<ScoreInfo> fetchData();
    int count();
};

#endif // DATASOURCE_H
