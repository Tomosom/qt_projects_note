#include <QtGui/QApplication>
#include <QWidget>
#include <QDialog>
#include <QDebug>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* 实验一: QWidget 与 QDialog 的区别测试 */
#if 0
#if 0
    /* 现象: 会生成两个窗口而不会嵌入 */
    /* 原因: QDialog不能作为子部件嵌入其它容器中 */
    QWidget widget;
    QDialog dialog(&widget);
#else
    /* 现象: 只有一个dialog窗口 */
    /* 原因: QWidget作为子部件嵌入到QDialog对象中 */
    QDialog dialog;
    QWidget widget(&dialog);
#endif
    dialog.show();
    dialog.setWindowTitle("i am dialog");
    widget.show();
    widget.setWindowTitle("i am widget");

    return a.exec();

#else

    /* 对话框功能测试 */
    Dialog dlg;
#if 0 /* 实验二: 对话框类型测试 */
    dlg.show(); /* 第一个窗口，非模态方式显示 */
    return a.exec();
#else /* 实验三: 返回值测试 */
    int r = dlg.exec(); /* 第一个窗口，模态方式显示 */
    if (r == QDialog::Accepted) {
        qDebug() << "Accepted";
    } else if (r == QDialog::Rejected) {
        qDebug() << "Rejected";
    } else {
        qDebug() << r;
    }
    //return a.exec(); /* 若用此返回,则程序最终必须强制关闭 */
    /*
     * 如果说我们要将一个对话框以模态对话框的方式运行的话,
     * 最后返回的就不应该是a.exec()了,而应返回用户的选择r变量。
     * a.exec()其实就是进入消息循环, 若返回a.exec()，则会有两次消息循环。
     */
    return r;
#endif
#endif

}
