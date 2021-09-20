#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QDebug>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    QPushButton b(&w);

    b.setText("Hello QT!");

    for (int i = 0; i < 10; i++) {
        qDebug() << i;
    }

    w.show();

    return a.exec();
}
