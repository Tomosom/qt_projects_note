#include <QtGui/QApplication>
#include "MainWindow.h"
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::NewInstance();
    int ret = -1;

    w->setFixedSize(600, 500);
    w->move((a.desktop()->width() - w->width()) / 2, (a.desktop()->height() - w->height()) / 2);

    if( w != NULL )
    {
        w->show();

        ret = a.exec();
    }

    delete w;

    return ret;
}
