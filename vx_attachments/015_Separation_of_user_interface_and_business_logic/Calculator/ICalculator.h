#ifndef ICALCULATOR_H
#define ICALCULATOR_H

#include <QString>

class ICalculator
{
public:
    /* 接收用户输入:四则运算表达式 */
    virtual bool expression(const QString &exp) = 0;
    /* 用来得到计算的结果 */
    virtual QString result() = 0;
};

#endif // ICALCULATOR_H
