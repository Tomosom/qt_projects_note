#include "UpdateThread.h"
#include <QApplication>
#include "StringEvent.h"

UpdateThread::UpdateThread(QObject *parent) :
    QThread(parent)
{
}

void UpdateThread::run()
{
    // emit updateUI("Begin");
    QApplication::postEvent(parent(), new StringEvent("Begin"));

    for(int i=0; i<10; i++)
    {
        // emit updateUI(QString::number(i));
        QApplication::postEvent(parent(), new StringEvent(QString::number(i)));

        sleep(1);
    }

    // emit updateUI("End");
    QApplication::postEvent(parent(), new StringEvent("End"));
}
