#include <QtGui/QApplication>
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* QWidget 与 QDialog 的区别测试 */
#if 0
#if 0
    QWidget widget;
    QDialog dialog(&widget); // 会生成两个窗口而不会嵌入
#endif
#if 1
    QDialog dialog;
    QWidget widget(&dialog); // 只有一个dialog窗口
#endif
    dialog.show();
    dialog.setWindowTitle("i am dialog");
    widget.show();
    widget.setWindowTitle("i am widget");

    return a.exec();
#endif

#if 1
    /* 对话框功能测试 */
    Dialog dlg;
#if 0
    /* 对话框类型测试 */
    dlg.show();
    return a.exec();
#else
    /* 返回值测试 */
    int r = dlg.exec();
    if (r == QDialog::Accepted) {
        qDebug() << "Accepted";
    } else if (r == QDialog::Rejected) {
        qDebug() << "Rejected";
    } else {
        qDebug() << r;
    }
    //return a.exec(); // 若用此返回,则程序最终必须强制关闭
    /*
     * 如果说我们要将一个对话框以模态对话框的方式运行的话,最后返回的就不是a.exec()了,而是返回用户的选择
     * a.exec()其实就是进入消息循环
     */
    return r;
#endif
#endif

}
