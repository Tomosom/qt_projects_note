#include <QtGui>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 1
    /* QWidget 相关功能测试 */
    //QWidget w;
    //QWidget w(NULL, Qt::Dialog);
    //QWidget w(NULL, Qt::Window);
    //QWidget w(NULL, Qt::SplashScreen);
    QWidget w(NULL, Qt::Window|Qt::WindowStaysOnTopHint|Qt::WindowContextHelpButtonHint);

    QLabel l(&w);

    l.setText("i am a label.");
    w.setWindowTitle("tomosom");
    // 设置窗口居中显示
    w.resize(300,  100);
    w.move((QApplication::desktop()->width() - w.width()) / 2,
           (QApplication::desktop()->height() - w.height()) / 2);
    w.show();
#else
    /* QLabel作为窗口,无实际意义 */
    QLabel l;
    l.setWindowTitle("tao");
    l.setText("i am a label.");
    l.show();
#endif

    return a.exec();
}
