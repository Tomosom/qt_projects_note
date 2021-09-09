/*
 * ����:����ʮ���Ƶ�����������ʽ
 */

#ifndef QCALCULATORDEC_H
#define QCALCULATORDEC_H

#include <QString>
#include <QStack>
#include <QQueue>

class QCalculatorDec
{
protected:
    QString m_exp; // ԭʼ���û������������ʽ
    QString m_result; //������

    bool isDigitOrDot(QChar c);
    bool isSymbol(QChar c);
    bool isSign(QChar c);
    bool isNumber(QString s);
    bool isOperator(QString s);
    bool isLeft(QString s);
    bool isRight(QString s);
    int priority(QString s);

    /* ƥ���㷨 */
    bool match(QQueue<QString> &exp);
    /* ���ո��ݺ�׺���ʽ������ */
    QString calculate(QQueue<QString> &exp);
    QString calculate(QString l, QString op, QString r);
    /* ��׺ת��׺ */
    bool transform(QQueue<QString> &exp, QQueue<QString> &output);
    /* �����㷨 */
    QQueue<QString> split(const QString& exp);

public:
    QCalculatorDec();
    ~QCalculatorDec();
    bool expression(const QString& exp);
    QString expression();
    QString result();
};

#endif // QCALCULATORDEC_H
