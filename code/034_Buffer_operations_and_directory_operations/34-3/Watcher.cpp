#include "Watcher.h"
#include <QDebug>

Watcher::Watcher(QObject *parent) : QObject(parent)
{
    connect(&m_watcher, SIGNAL(fileChanged(const QString&)),
            this, SLOT(statusChanged(const QString&)));
    connect(&m_watcher, SIGNAL(directoryChanged(const QString&)),
            this, SLOT(statusChanged(const QString&)));
}

void Watcher::statusChanged(const QString &path)
{
    qDebug() << path << "is changed!";
}

void Watcher::addPath(QString path)
{
    m_watcher.addPath(path);
}
