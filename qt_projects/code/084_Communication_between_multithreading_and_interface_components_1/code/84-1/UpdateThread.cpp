#include "UpdateThread.h"

UpdateThread::UpdateThread(QObject *parent) :
    QThread(parent)
{
}

void UpdateThread::run()
{
    emit updateUI("Begin");

    for(int i=0; i<10; i++)
    {
        emit updateUI(QString::number(i));

        sleep(1);
    }

    emit updateUI("End");
}
