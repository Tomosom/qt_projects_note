#ifndef QCALCULATOR_H
#define QCALCULATOR_H

#include "QCalculatorUI.h"
#include "QCalculatorDec.h"

class QCalculator
{
protected:
    QCalculatorUI *m_ui; /* 因ui使用二阶构造实现的,因此必须定义成指针 */
    QCalculatorDec m_cal;

    /* 若有成员是二阶构造实现的,则该类也需使用二阶构造实现 */
    QCalculator();
    bool construct();
public:
    static QCalculator *NewInstance();
    void show();
    ~QCalculator();
};

#endif // QCALCULATOR_H
