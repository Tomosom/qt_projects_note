#include <QtCore/QCoreApplication>
#include "Watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Watcher watcher;

    watcher.addPath("text.txt");
    watcher.addPath("QDir");

    return a.exec();
}
