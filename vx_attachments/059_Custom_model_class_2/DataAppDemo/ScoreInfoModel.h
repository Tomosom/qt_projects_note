#ifndef SCOREINFOMODEL_H
#define SCOREINFOMODEL_H

#include <QObject>
#include <QStandardItem>
#include <QTableView>
#include "ScoreInfo.h"

class ScoreInfoModel : public QObject
{
    Q_OBJECT

    QStandardItemModel m_model;
public:
    explicit ScoreInfoModel(QObject *parent = 0);
    bool add(ScoreInfo info);
    bool remove(int i);
    ScoreInfo getItem(int i);
    int count();
    void setView(QTableView& view);
};

#endif // SCOREINFOMODEL_H
