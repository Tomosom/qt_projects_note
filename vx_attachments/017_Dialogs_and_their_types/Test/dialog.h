#ifndef DIALOG_H
#define DIALOG_H

#include <QtGui/QDialog>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT
protected:
    QPushButton ModalBtn;
    QPushButton ModelessBtn;
    QPushButton MixedBtn;
protected slots:
    void ModalBtn_Clicked();
    void ModelessBtn_Clicked();
    void MixedBtn_Clicked();
public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
};

#endif // DIALOG_H
