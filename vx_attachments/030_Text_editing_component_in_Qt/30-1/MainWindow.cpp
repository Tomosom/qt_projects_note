#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
  lineEdit(this), plainEdit(this), textEdit(this) // 设置3个文本编辑器的父类
{
    resize(600, 420);

    /* QLineEdit */
    lineEdit.move(20, 20);
    lineEdit.resize(560, 100);
    lineEdit.insert("QLineEdit");
    lineEdit.insert("\n"); /* 换行无作用 */
    lineEdit.insert("<img src=\":/res/D.T.png\" />");

    /* QPlainTextEdit */
    plainEdit.move(20, 130);
    plainEdit.resize(560, 130);
    plainEdit.insertPlainText("QPlainTextEdit");
    plainEdit.insertPlainText("\n");
    plainEdit.insertPlainText("<img src=\":/res/D.T.png\" />");

    /* QTextEdit */
    textEdit.move(20, 270);
    textEdit.resize(560, 130);
#if 0
    textEdit.insertPlainText("QTextEdit");
    textEdit.insertPlainText("\n");
    textEdit.insertPlainText("<img src=\":/res/D.T.png\" />");
#else
    textEdit.insertHtml("QTextEdit");
    textEdit.insertHtml("<br>"); /* 在 html 中 "\n" 不代表换行 */
    textEdit.insertHtml("<img src=\":/res/D.T.png\" />");
#endif
}

MainWindow::~MainWindow()
{
    
}
