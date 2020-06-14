#include "ScoreInfo.h"

ScoreInfo::ScoreInfo(QObject* parent) : QObject(parent)
{
    m_id = "NULL";
    m_name = "NULL";
    m_score = -1;
}

ScoreInfo::ScoreInfo(QString id, QString name, int score, QObject* parent)
{
    m_id = id;
    m_name = name;
    m_score = score;
}

ScoreInfo::ScoreInfo(const ScoreInfo& obj)
{
    m_id = obj.m_id;
    m_name = obj.m_name;
    m_score = obj.m_score;
}

ScoreInfo& ScoreInfo::operator= (const ScoreInfo& obj)
{
    if( this != &obj )
    {
        m_id = obj.m_id;
        m_name = obj.m_name;
        m_score = obj.m_score;
    }

    return *this;
}

QString ScoreInfo::id()
{
    return m_id;
}

QString ScoreInfo::name()
{
    return m_name;
}

int ScoreInfo::score()
{
    return m_score;
}
