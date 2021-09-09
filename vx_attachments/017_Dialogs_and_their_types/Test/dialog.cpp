#include "Dialog.h"

#include <QDebug>

Dialog::Dialog(QWidget *parent) :
        QDialog(parent), ModalBtn(this), NormalBtn(this), MixedBtn(this)
{
    ModalBtn.setText("Modal Dialog");
    ModalBtn.move(20, 20);
    ModalBtn.resize(100, 30);

    NormalBtn.setText("Normal Dialog");
    NormalBtn.move(20, 70);
    NormalBtn.resize(100, 30);

    MixedBtn.setText("Mixed Dialog");
    MixedBtn.move(20, 120);
    MixedBtn.resize(100, 30);

    connect(&ModalBtn, SIGNAL(clicked()), this, SLOT(ModalBtn_Clicked()));
    connect(&NormalBtn, SIGNAL(clicked()), this, SLOT(NormalBtn_Clicked()));
    connect(&MixedBtn, SIGNAL(clicked()), this, SLOT(MixedBtn_Clicked()));

    resize(140, 170);
}

void Dialog::ModalBtn_Clicked()
{
    qDebug() << "ModalBtn_Clicked() Begin";

#if 0
    /* �Ի������Ͳ��� */
    QDialog dialog(this);
    dialog.exec();
#else
    /* ����ֵ���� */
    done(Accepted);
#endif
    qDebug() << "ModalBtn_Clicked() End";
}

void Dialog::NormalBtn_Clicked()
{
    qDebug() << "NormalBtn_Clicked() Begin";
#if 0
    /* �Ի������Ͳ��� */
#if 0
    /* ����ջ�϶���,���һ������ */
    //QDialog dialog;
    QDialog dialog(this); // �Ƿ�ָ�������,Ч������һ����
    dialog.show();
#else
    /* �ڶ��ϴ��� */
    //QDialog* dialog = new QDialog; // ����ָ�������,���Ƕ����Ĵ���
    //QDialog* dialog = new QDialog(this); // Ĭ���Ƿ�ģ̬�Ի���,��ʼ��λ�ڸ����ڵ�����
    QDialog* dialog = new Dialog(this); // ���ô˶������Qt::WA_DeleteOnClose����

    dialog->setAttribute(Qt::WA_DeleteOnClose); // �رնԻ���ʱ,�ͷ��ڴ�ռ�
    dialog->show();
#endif
#else
    /* ����ֵ���� */
    done(Rejected);
#endif

    qDebug() << "NormalBtn_Clicked() End";
}

void Dialog::MixedBtn_Clicked()
{
    qDebug() << "MixedBtn_Clicked() Begin";
#if 0
    /* �Ի������Ͳ��� */
    QDialog* dialog = new QDialog(this);

    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setModal(true);
    dialog->show();
#else
    /* ����ֵ���� */
    done(100);
#endif
    qDebug() << "MixedBtn_Clicked() End";
}

Dialog::~Dialog()
{
    qDebug() << "~Dialog()";
}
