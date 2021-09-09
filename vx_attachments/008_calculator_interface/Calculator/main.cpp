#include <QtGui/QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *w = new QWidget(NULL, Qt::WindowCloseButtonHint);  // 隐藏最大最小化按钮
    QLineEdit *le = new QLineEdit(w);
    QPushButton *button[20] = {0};
    const char *btnText[20] = {
        "7","8","9","+","(",
        "4","5","6","-",")",
        "1","2","3","*","<-",
        "0",".","=","/","C"
    };

    int ret = 0;

    le->move(10, 10);
    le->resize(240, 30);
    le->setReadOnly(true);  // 设置文本框只读

    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            button[i * 5 + j] = new QPushButton(w);
            button[i * 5 + j]->resize(40, 40);
            button[i * 5 + j]->move(10 + (10 + 40) * j, 50 + (10 + 40) * i);
            button[i * 5 + j]->setText(btnText[i * 5 + j]);
        }
    }

    w->show();
    w->setFixedSize(w->width(), w->height());   // 固定窗口大小

    ret = a.exec();

    delete w;

    return ret;
}
