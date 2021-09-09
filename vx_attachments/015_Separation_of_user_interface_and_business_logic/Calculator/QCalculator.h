#ifndef QCALCULATOR_H
#define QCALCULATOR_H

#include "QCalculatorUI.h"
#include "QCalculatorDec.h"

class QCalculator
{
protected:
    QCalculatorUI *m_ui;    // ��uiʹ�ö��׹���ʵ�ֵ�,��˱��붨���ָ��
    QCalculatorDec m_cal;

    /* ���г�Ա�Ƕ��׹���ʵ�ֵ�,�����Ҳ��ʹ�ö��׹���ʵ�� */
    QCalculator();
    bool construct();
public:
    static QCalculator *NewInstance();
    void show();
    ~QCalculator();
};

#endif // QCALCULATOR_H
