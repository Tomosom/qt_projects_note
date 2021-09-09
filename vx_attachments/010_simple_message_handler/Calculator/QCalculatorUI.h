#ifndef QCALCULATORUI_H
#define QCALCULATORUI_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class QCalculatorUI : public QWidget
{
    Q_OBJECT
private:
    QLineEdit *m_edit;
    QPushButton *m_button[20];

    // 避免生成半成品,二阶构造法
    QCalculatorUI();
    bool construct();

private slots:
    void onButtonClicked();

public:
    static QCalculatorUI *NewInstance();

    void show();

    ~QCalculatorUI();

};

#endif // QCALCULATORUI_H
