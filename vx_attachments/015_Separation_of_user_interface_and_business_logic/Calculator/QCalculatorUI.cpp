#include "QCalculatorUI.h"
//#include "QCalculatorDec.h"
#include <QDebug>

QCalculatorUI::QCalculatorUI() : QWidget(NULL, Qt::WindowCloseButtonHint) // 顶层窗口界面类
{
    m_cal = NULL;
    //m_edit = new QLineEdit(this);
}

bool QCalculatorUI::construct()
{
    bool ret = true;

    const char *btnText[20] = {
        "7","8","9","+","(",
        "4","5","6","-",")",
        "1","2","3","*","<-",
        "0",".","=","/","C"
    };
    m_edit = new QLineEdit(this);
    if (m_edit != NULL) {
        m_edit->move(10, 10);
        m_edit->resize(240, 30);
        m_edit->setReadOnly(true);  // 设置文本框只读
        m_edit->setAlignment(Qt::AlignRight);
    } else {
        return false;
    }

    for(int i = 0; (i < 4) && ret; i++) {
        for (int j = 0; (j < 5) && ret; j++) {
            m_button[i * 5 + j] = new QPushButton(this);
            if (m_button[i * 5 + j] != NULL) {
                m_button[i * 5 + j]->resize(40, 40);
                m_button[i * 5 + j]->move(10 + (10 + 40) * j, 50 + (10 + 40) * i);
                m_button[i * 5 + j]->setText(btnText[i * 5 + j]);
                connect(m_button[i * 5 + j], SIGNAL(clicked()), this, SLOT(onButtonClicked()));
            } else {
                ret = false;
            }
        }
    }

    return ret;
}

// 二阶构造法,要么得到一个完全的对象,要么得到一个空指针,不会得到一个半成品对象
QCalculatorUI *QCalculatorUI::NewInstance()
{
    QCalculatorUI *ret = new QCalculatorUI();

    if ( (ret == NULL) ||  (!ret->construct()) ) {
        delete ret;
        ret = NULL;
    }

    return ret;
}

void QCalculatorUI::show()
{
    QWidget::show();
    setFixedSize(width(), height());   // 固定窗口大小
}

void QCalculatorUI::onButtonClicked()
{
    QPushButton *btn = dynamic_cast<QPushButton*>(sender()); // 得到被点击的按钮指针
    if(btn != NULL) {
        QString clickText = btn->text();

        if (clickText == "<-") {
            QString text = m_edit->text();
            if (text.length() > 0) {
                text.remove(text.length() - 1, 1);
                m_edit->setText(text);
            }
        } else if (clickText == "C") {
            m_edit->setText("");
        } else if (clickText == "=") {
            //QCalculatorDec c;
            //c.expression(m_edit->text());
            //m_edit->setText(c.result());
            if (m_cal != NULL) {
                m_cal->expression(m_edit->text());
                m_edit->setText(m_cal->result());
            }
        } else {
            m_edit->setText(m_edit->text() + clickText);
        }

        //QString text = m_edit->text() + btn->text();
        //m_edit->setText(text);
        //qDebug()<<"onButtonClicked()";
        //qDebug()<<btn->text();
    }
}

void QCalculatorUI::setCalculator(ICalculator *cal)
{
    m_cal = cal;
}

ICalculator *QCalculatorUI::getCalculator()
{
    return m_cal;
}

QCalculatorUI::~QCalculatorUI() // 顶层窗口界面类
{
}
