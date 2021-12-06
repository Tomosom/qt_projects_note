#include "MainWindow.h"
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    QToolBar *tb = addToolBar("Tool Bar");
    QAction *action = new QAction("", NULL);

    /* 工具栏位置写死 */
    tb->setFloatable(false);
    tb->setMovable(false);

    action->setToolTip("Open"); /* 鼠标悬停提示 */
    action->setIcon(QIcon(":/Res/open.png")); /* 需传QIcon的对象 */

    tb->addAction(action);

    /* 工具栏中可添加widget对象 */
    QPushButton *b = new QPushButton("Button");
    QLabel *l = new QLabel("Label");
    QLineEdit *e = new QLineEdit();
    tb->addWidget(b);
    tb->addWidget(l);
    tb->addWidget(e);
}

MainWindow::~MainWindow()
{
}
