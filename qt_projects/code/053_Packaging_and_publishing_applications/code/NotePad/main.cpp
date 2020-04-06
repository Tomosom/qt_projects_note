#include <QtGui/QApplication>
#include <QFileInfo>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::NewInstance();
    int ret = -1;

    if( w != NULL )
    {
        if( argc > 1 )
        {
            QFileInfo fi(argv[1]);

            if( fi.exists() )
            {
                w->openFile(fi.absoluteFilePath());
            }
        }

        w->show();

        ret = a.exec();
    }

    delete w;

    return ret;
}
