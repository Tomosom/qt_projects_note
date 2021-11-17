#include "MainWindow.h"
#include <QMenu>

MainWindow::MainWindow()
{
}

/* 使用了二阶构造 */
MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret = new MainWindow();
    if ((ret == NULL) || !ret->construct()) {
        delete ret;
        ret = NULL;
    }
    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;
    ret = ret && initMenuBar();
    return ret;
}

bool MainWindow::initMenuBar()
{
    bool ret = true;
    QMenuBar* mb = menuBar();
    ret = ret && initFileMenu(mb);
    return ret;
}

bool MainWindow::initFileMenu(QMenuBar* mb)
{
    QMenu *menu = new QMenu("File(&F)"); /* ALT + F 快捷键打开菜单 */
    bool ret = (menu != NULL);
    if (ret) {
        QAction* action = NULL;
        ret = ret && makeAction(action, "New(N)", Qt::CTRL + Qt::Key_N);
        if (ret) {
            menu->addAction(action); /* add Action item to Menu */
        }
        menu->addSeparator(); /* 创建分隔符 */
        ret = ret && makeAction(action, "Exit(X)", Qt::CTRL + Qt::Key_X);
        if (ret) {
            menu->addAction(action); /* add Action item to Menu */
        }
    }
    if (ret) {
        mb->addMenu(menu); /* add Menu add to application Menu Bar */
    } else {
        delete menu;
    }
    return ret;
}

bool MainWindow::makeAction(QAction*& action, QString text, int key)
{
    bool ret = true;
    action = new QAction(text, NULL); /* 不用指定父对象，后面addAction时会自动指定父对象 */
    if (action != NULL) {
        action->setShortcut(QKeySequence(key));
    } else {
        ret = false;
    }
    return ret;
}

MainWindow::~MainWindow()
{
}
