/*
 * 功能:计算十进制的四则运算表达式
 */

#ifndef QCALCULATORDEC_H
#define QCALCULATORDEC_H

#include <QString>
#include <QStack>
#include <QQueue>

class QCalculatorDec
{
protected:
    QString m_exp; // 原始的用户输入的四则表达式
    QString m_result; //计算结果

    bool isDigitOrDot(QChar c);
    bool isSymbol(QChar c);
    bool isSign(QChar c);
    bool isNumber(QString s);
    bool isOperator(QString s);
    bool isLeft(QString s);
    bool isRight(QString s);
    int priority(QString s);

    /* 匹配算法 */
    bool match(QQueue<QString> &exp);
    /* 最终根据后缀表达式计算结果 */
    QString calculate(QQueue<QString> &exp);
    QString calculate(QString l, QString op, QString r);
    /* 中缀转后缀 */
    bool transform(QQueue<QString> &exp, QQueue<QString> &output);
    /* 分离算法 */
    QQueue<QString> split(const QString& exp);

public:
    QCalculatorDec();
    ~QCalculatorDec();
    bool expression(const QString& exp);
    QString expression();
    QString result();
};

#endif // QCALCULATORDEC_H
