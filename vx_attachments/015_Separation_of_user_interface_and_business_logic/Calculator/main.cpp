#include <QtGui/QApplication>
//#include "QCalculatorUI.h"
//#include "QCalculatorDec.h"

#include "QCalculator.h"
//#include <QDebug>

int main(int argc, char *argv[])
{
#if 1
    QApplication a(argc, argv);
    int ret = -1;
    QCalculator *cal = QCalculator::NewInstance();
    if (cal != NULL) {
        cal->show();
        ret = a.exec();

        delete cal;
    }

    return ret;
#else
    QCalculatorDec c;

    //c.expression("5 * 8");
    //c.expression("5 - 8 * (5-6)");
    c.expression("(5 - 8) * (5-6)");
    qDebug()<<c.result();
    return 0;
#endif

}
