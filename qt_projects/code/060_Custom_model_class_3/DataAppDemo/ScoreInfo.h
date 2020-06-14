#ifndef SCOREINFO_H
#define SCOREINFO_H

#include <QObject>

class ScoreInfo : public QObject
{
    Q_OBJECT

    QString m_id;
    QString m_name;
    int m_score;
public:
    explicit ScoreInfo(QObject* parent = 0);
    explicit ScoreInfo(QString id, QString name, int score, QObject* parent = 0);
    ScoreInfo(const ScoreInfo& obj);
    ScoreInfo& operator= (const ScoreInfo& obj);
    QString id();
    QString name();
    int score();
    
};

#endif // SCOREINFO_H
