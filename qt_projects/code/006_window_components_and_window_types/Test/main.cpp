#include <QtGui>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 1
    /* QWidget 相关功能测试 */
    //QWidget w;
    //QWidget w(NULL, Qt::Dialog);
    QWidget w(NULL, Qt::Window|Qt::WindowStaysOnTopHint|Qt::WindowContextHelpButtonHint);
    //QWidget w(NULL, Qt::SplashScreen);

    QLabel l(&w);

    l.setText("i am a label.");

    w.setWindowTitle("tao");
    w.resize(400, 300);
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
