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

    sb->addPermanentWidget(l);
    sb->addPermanentWidget(e);
    sb->addPermanentWidget(b);

    sb->showMessage("D.T.Software");
}

MainWindow::~MainWindow()
{
    
}
