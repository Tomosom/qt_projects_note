#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "QLoginDialog.h"

class MainWin : public QWidget
{
    Q_OBJECT

    QVBoxLayout vMainLayout;
    QGroupBox msgGrpBx;
    QGroupBox inputGrpBx;
    QPlainTextEdit msgEditor;
    QLineEdit inputEdit;
    QPushButton logInOutBtn;
    QPushButton sendBtn;
    QLabel statusLbl;
    QLoginDialog loginDlg;

    void initMsgGrpBx();
    void initInputGrpBx();
    void connectSlots();
private slots:
    void sendBtnClicked();
    void logInOutBtnClicked();
public:
    MainWin(QWidget *parent = 0);
    ~MainWin();
};

#endif // MAINWIN_H
