#include "MainWindow.h"
#include <QMenu>
#include <QIcon>
#include <QSize>
#include <QStatusBar>
#include <QLabel>

MainWindow::MainWindow()
{

}

MainWindow* MainWindow::NewInstance()
{
    MainWindow* ret = new MainWindow();

    if( (ret == NULL) || !ret->construct() )
    {
        delete ret;
        ret = NULL;
    }

    return ret;
}

bool MainWindow::construct()
{
    bool ret = true;

    ret = ret && initMenuBar();
    ret = ret && initToolBar();
    ret = ret && initStatusBar();

    return ret;
}

bool MainWindow::initMenuBar()
{
    bool ret = true;
    QMenuBar* mb = menuBar();

    ret = ret && initFileMenu(mb);
    ret = ret && initEditMenu(mb);
    ret = ret && initFormatMenu(mb);
    ret = ret && initViewMenu(mb);
    ret = ret && initHelpMenu(mb);

    return ret;
}

bool MainWindow::initToolBar()
{
    bool ret = true;
    QToolBar* tb = addToolBar("Tool Bar");

    tb->setIconSize(QSize(16, 16));

    ret = ret && initFileToolItem(tb);

    tb->addSeparator();

    ret = ret && initEditToolItem(tb);

    tb->addSeparator();

    ret = ret && initFormatToolItem(tb);

    tb->addSeparator();

    ret = ret && initViewToolItem(tb);

    return ret;
}

bool MainWindow::initStatusBar()
{
    bool ret = true;
    QStatusBar* sb = statusBar();
    QLabel* label = new QLabel("D.T.Software");

    if( label != NULL )
    {
        label->setMinimumWidth(200);
        label->setAlignment(Qt::AlignCenter);

        sb->addPermanentWidget(label);
    }
    else
    {
        ret = false;
    }

    return ret;
}

bool MainWindow::initFileMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("File(&F)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && makeAction(action, "New(&N)", Qt::CTRL + Qt::Key_N);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Open(&O)...", Qt::CTRL + Qt::Key_O);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Save(&S)", Qt::CTRL + Qt::Key_S);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Save As(&A)...", 0);

        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Print(&P)...", Qt::CTRL + Qt::Key_P);

        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Exit(&X)", 0);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initEditMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Edit(&E)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && makeAction(action, "Undo(&U)", Qt::CTRL + Qt::Key_Z);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Redo(&R)...", Qt::CTRL + Qt::Key_Y);

        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Cut(&T)", Qt::CTRL + Qt::Key_X);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Copy(&C)...", Qt::CTRL + Qt::Key_C);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Paste(&P)...", Qt::CTRL + Qt::Key_V);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Delete(&L)", Qt::Key_Delete);

        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Find(&F)...", Qt::CTRL + Qt::Key_F);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Replace(&R)...", Qt::CTRL + Qt::Key_H);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Goto(&G)...", Qt::CTRL + Qt::Key_G);

        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Select All(&A)", Qt::CTRL + Qt::Key_A);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initFormatMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Format(&O)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && makeAction(action, "Auto Wrap(&W)", 0);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Font(&F)...", 0);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initViewMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("View(&V)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && makeAction(action, "Tool Bar(&T)", 0);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Status Bar(&S)", 0);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initHelpMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Help(&H)");
    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = NULL;

        ret = ret && makeAction(action, "User Manual", 0);

        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "About NotePad...", 0);

        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}

bool MainWindow::initFileToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action, "New", ":/res/pic/new.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Open", ":/res/pic/open.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Save", ":/res/pic/save.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Save As", ":/res/pic/saveas.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Print", ":/res/pic/print.png");

    if( ret )
    {
        tb->addAction(action);
    }


    return ret;
}

bool MainWindow::initEditToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action, "Undo", ":/res/pic/undo.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Redo", ":/res/pic/redo.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Cut", ":/res/pic/cut.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Copy", ":/res/pic/copy.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Paste", ":/res/pic/paste.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Find", ":/res/pic/find.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Replace", ":/res/pic/replace.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Goto", ":/res/pic/goto.png");

    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::initFormatToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action, "Auto Wrap", ":/res/pic/wrap.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Font", ":/res/pic/font.png");

    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::initViewToolItem(QToolBar* tb)
{
    bool ret = true;
    QAction* action = NULL;

    ret = ret && makeAction(action, "Tool Bar", ":/res/pic/tool.png");

    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Status Bar", ":/res/pic/status.png");

    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}

bool MainWindow::makeAction(QAction*& action, QString text, int key)
{
    bool ret = true;

    action = new QAction(text, NULL);

    if( action != NULL )
    {
        action->setShortcut(QKeySequence(key));
    }
    else
    {
        ret = false;
    }

    return ret;
}

bool MainWindow::makeAction(QAction*& action, QString tip, QString icon)
{
    bool ret = true;

    action = new QAction("", NULL);

    if( action != NULL )
    {
        action->setToolTip(tip);
        action->setIcon(QIcon(icon));
    }
    else
    {
        ret = false;
    }

    return ret;
}

MainWindow::~MainWindow()
{
    
}
