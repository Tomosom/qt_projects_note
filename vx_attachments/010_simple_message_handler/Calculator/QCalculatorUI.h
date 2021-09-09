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

    // �������ɰ��Ʒ,���׹��취
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
