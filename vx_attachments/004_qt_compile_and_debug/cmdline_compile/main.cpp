#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    QPushButton b(&w);

    b.setText("Hello QT!");

    w.show();

    return a.exec();
}
