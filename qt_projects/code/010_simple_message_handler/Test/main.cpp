#include <QtGui/QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton b;
    b.setText("click me to quit!");
    b.show();

    QObject::connect(&b, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
