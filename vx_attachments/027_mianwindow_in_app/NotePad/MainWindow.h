#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include <QtGui/QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QAction>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    MainWindow();
    MainWindow(const MainWindow&);
    MainWindow& operator= (const MainWindow&);

    bool construct();
    bool initMenuBar();
    bool initFileMenu(QMenuBar* mb);
    bool makeAction(QAction*& action, QString text, int key);
public:
    static MainWindow* NewInstance(); /* 二阶构造 */
    ~MainWindow();
};

#endif // _MAINWINDOW_H_
