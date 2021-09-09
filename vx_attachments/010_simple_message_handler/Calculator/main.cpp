#include <QtGui/QApplication>
#include "QCalculatorUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int ret = -1;
    QCalculatorUI *cal = QCalculatorUI::NewInstance();
    if (cal != NULL) {
        cal->show();
        ret = a.exec();

        delete cal;
    }

    return ret;
}
