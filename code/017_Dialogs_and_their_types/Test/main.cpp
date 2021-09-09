#include <QtGui/QApplication>
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* QWidget �� QDialog ��������� */
#if 0
#if 0
    QWidget widget;
    QDialog dialog(&widget); // �������������ڶ�����Ƕ��
#endif
#if 1
    QDialog dialog;
    QWidget widget(&dialog); // ֻ��һ��dialog����
#endif
    dialog.show();
    dialog.setWindowTitle("i am dialog");
    widget.show();
    widget.setWindowTitle("i am widget");

    return a.exec();
#endif

#if 1
    /* �Ի����ܲ��� */
    Dialog dlg;
#if 0
    /* �Ի������Ͳ��� */
    dlg.show();
    return a.exec();
#else
    /* ����ֵ���� */
    int r = dlg.exec();
    if (r == QDialog::Accepted) {
        qDebug() << "Accepted";
    } else if (r == QDialog::Rejected) {
        qDebug() << "Rejected";
    } else {
        qDebug() << r;
    }
    //return a.exec(); // ���ô˷���,��������ձ���ǿ�ƹر�
    /*
     * ���˵����Ҫ��һ���Ի�����ģ̬�Ի���ķ�ʽ���еĻ�,��󷵻صľͲ���a.exec()��,���Ƿ����û���ѡ��
     * a.exec()��ʵ���ǽ�����Ϣѭ��
     */
    return r;
#endif
#endif

}
