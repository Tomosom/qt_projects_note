#include "QCalculatorDec.h"

//#include <QDebug>

QCalculatorDec::QCalculatorDec()
{
    m_exp = "";
    m_result = "";

#if 0
    QQueue<QString> r = split("+9.11 + ( -3 - 1 ) * -5 ");
    //QQueue<QString> r = split("+9.11 + -3 - 1 ) * -5 ");

    for(int i=0; i<r.length(); i++)
    {
        qDebug() << r[i];
    }

    //qDebug() << match(r);
    qDebug() << "";
    QQueue<QString> output;
    transform(r, output);
    for(int i=0; i < output.length(); i++)
    {
        qDebug() << output[i];
    }
#endif
}

QCalculatorDec::~QCalculatorDec()
{

}

bool QCalculatorDec::isDigitOrDot(QChar c)
{
    return (('0' <= c) && (c <= '9')) || (c == '.');
}

bool QCalculatorDec::isSymbol(QChar c)
{
    return isOperator(c) || (c == '(') || (c == ')');
}

bool QCalculatorDec::isSign(QChar c)
{
    return (c == '+') || (c == '-');
}

bool QCalculatorDec::isNumber(QString s)
{
    bool ret = false;

    s.toDouble(&ret);

    return ret;
}

bool QCalculatorDec::isOperator(QString s)
{
    return (s == "+") || (s == "-") || (s == "*") || (s == "/");
}

bool QCalculatorDec::isLeft(QString s)
{
    return (s == "(");
}

bool QCalculatorDec::isRight(QString s)
{
    return (s == ")");
}

int QCalculatorDec::priority(QString s)
{
    int ret = 0;

    if( (s == "+") || (s == "-") )
    {
        ret = 1;
    }

    if( (s == "*") || (s == "/") )
    {
        ret = 2;
    }

    return ret;
}

bool QCalculatorDec::expression(const QString& exp)
{
    bool ret = false;

    QQueue<QString> spExp = split(exp);
    QQueue<QString> posExp; //

    m_exp = exp;

    if (transform(spExp, posExp)) {
        m_result = calculate(posExp);
        ret = (m_result != "Error");
    } else {
        m_result = "Error";
    }

    return ret;
}

QString QCalculatorDec::result()
{
    return m_result;
}

QQueue<QString> QCalculatorDec::split(const QString& exp)
{
    QQueue<QString> ret;
    QString num = "";
    QString pre = ""; //

    for(int i=0; i<exp.length(); i++) {
        if( isDigitOrDot(exp[i]) ) {
            num += exp[i];
            pre = exp[i];
        }
        else if( isSymbol(exp[i]) ) {
            if( !num.isEmpty() ) {
                ret.enqueue(num);
                num.clear();
            }

            if( isSign(exp[i]) && ((pre == "") || (pre == "(") || isOperator(pre)) ) {
                num += exp[i];
            } else {
                ret.enqueue(exp[i]);
            }

            pre = exp[i];
        }
    }

    if( !num.isEmpty() ) {
        ret.enqueue(num);
    }

    return ret;
}

bool QCalculatorDec::match(QQueue<QString> &exp)
{
    bool ret = true;
    int len = exp.length();
    QStack<QString> stack;

    for (int i = 0; i < len; i++) {
        if ( isLeft(exp[i]) ) {
            stack.push(exp[i]);
        } else if ( isRight(exp[i]) ) {
            if (!stack.isEmpty() && isLeft(stack.top())) {
                stack.top();
            } else {
                ret = false;
                break;
            }
        }
    }

    return ret;
}

bool QCalculatorDec::transform(QQueue<QString> &exp, QQueue<QString> &output)
{
    bool ret = match(exp);
    QStack<QString> stack;

    output.clear();

    while(ret && !exp.isEmpty()) {
        QString e =exp.dequeue();
        if (isNumber(e)) {
            output.enqueue(e);
        } else if (isOperator(e)) {
            while( !stack.isEmpty() && (priority(e) <= priority(stack.top())) ) {
                output.enqueue(stack.pop());
            }
            stack.push(e);
        } else if (isLeft(e)) {
            stack.push(e);
        } else if (isRight(e)) {
            while ( !stack.isEmpty() && !isLeft(stack.top()) ) {
                output.enqueue(stack.pop());
            }

            if ( !stack.isEmpty() ) {
                stack.pop();
            }
        } else {
            ret = false;
        }
    }

    while (!stack.isEmpty()) {
        output.enqueue(stack.pop());
    }

    if (!ret) {
        output.clear();
    }

    return ret;
}

QString QCalculatorDec::calculate(QString l, QString op, QString r)
{
    QString ret = "Error";

    if (isNumber(l) && isNumber(r)) {
        double lp = l.toDouble();
        double rp = r.toDouble();

        if (op == "+") {
            ret.sprintf("%f", lp + rp);
        } else if (op == "-") {
            ret.sprintf("%f", lp - rp);
        } else if (op == "*") {
            ret.sprintf("%f", lp * rp);
        } else if (op == "/") {
            const double P = 0.0000000000000001;
            if ( (-P < rp) && (rp < P) ) {
                ret = "Error";
            } else {
                ret.sprintf("%f", lp / rp);
            }
        } else {
            ret = "Error";
        }

    }

    return ret;
}

QString QCalculatorDec::calculate(QQueue<QString> &exp)
{
    QString ret = "Error";
    QStack<QString> stack;

    while(!exp.isEmpty()) {
        QString e = exp.dequeue();

        if (isNumber(e)) {
            stack.push(e);
        } else if (isOperator(e)) {
            // 1. 从栈中弹出右操作数;
            QString rp = !stack.isEmpty() ? stack.pop() : "";
            // 2. 从栈中弹出左操作数;
            QString lp = !stack.isEmpty() ? stack.pop() : "";
            // 3. 根据符号进行运算;
            QString result = calculate(lp, e, rp);
            // 4. 将运算结果压入栈中;
            if (result != "Error") {
                stack.push(result);
            } else {
                break;
            }

        } else {
            break;
        }
    }

    if (exp.isEmpty() && (stack.size() == 1) && isNumber(stack.top())) {
        ret = stack.pop();
    }

    return ret;
}

