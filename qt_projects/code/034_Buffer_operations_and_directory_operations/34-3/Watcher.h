#ifndef _WATCHER_H_
#define _WATCHER_H_

#include <QObject>
#include <QFileSystemWatcher>

class Watcher : public QObject
{
    Q_OBJECT

    QFileSystemWatcher m_watcher;
private slots:
    void statusChanged(const QString& path);
public:
    explicit Watcher(QObject *parent = 0);
    void addPath(QString path);
};

#endif // WATCHER_H
