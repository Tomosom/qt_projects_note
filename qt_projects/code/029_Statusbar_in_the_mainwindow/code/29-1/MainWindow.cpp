#include "MainWindow.h"
#include <QStatusBar>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QStatusBar* sb = statusBar();
    QLabel* l = new QLabel("Label");
    QLineEdit* e = new QLineEdit();
    QPushButton* b = new QPushButton("Button");
#if 1
    sb->addPermanentWidget(l); // 右半部分显示
    sb->addPermanentWidget(e);
    sb->addPermanentWidget(b);
#else
    sb->addWidget(l); // 左半部分显示
    sb->addWidget(e);
    sb->addWidget(b);
#endif
    sb->showMessage("D.T.Software"); // 左半部分显示
}

MainWindow::~MainWindow()
{
    
}
