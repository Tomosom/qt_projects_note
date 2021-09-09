#ifndef _FINDDIALOG_H_
#define _FINDDIALOG_H_

#include <QDialog>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QGroupBox>

class FindDialog : public QDialog
{
    Q_OBJECT

protected:
    QGroupBox m_radioGrpBx;

    QGridLayout m_layout;
    QHBoxLayout m_hbLayout;

    QLabel m_findLbl;
    QLineEdit m_findEdit;
    QPushButton m_findBtn;
    QPushButton m_closeBtn;
    QCheckBox m_matchChkBx;
    QRadioButton m_forwardBtn;
    QRadioButton m_backwardBtn;

public:
    explicit FindDialog(QWidget* parent = 0);
    bool event(QEvent* evt);
    
signals:
    
public slots:
    
};

#endif // _FINDDIALOG_H_
