#include <QtCore/QCoreApplication>
#include "Watcher.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Watcher watcher;

    watcher.addPath("C:/Users/hp/Desktop/text.txt");
    watcher.addPath("C:/Users/hp/Desktop/QDir");
    
    return a.exec();
}
