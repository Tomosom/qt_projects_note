#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
  lineEdit(this), plainEdit(this), textEdit(this) // ����3���ı��༭���ĸ���
{
    resize(600, 420);

    lineEdit.move(20, 20);
    lineEdit.resize(560, 100);
    lineEdit.insert("QLineEdit");
    lineEdit.insert("\n");
    lineEdit.insert("<img src=\"C:\\Users\\hp\\Desktop\\D.T.png\" />");

    plainEdit.move(20, 130);
    plainEdit.resize(560, 130);
    plainEdit.insertPlainText("QPlainTextEdit");
    plainEdit.insertPlainText("\n");
    plainEdit.insertPlainText("<img src=\"C:\\Users\\hp\\Desktop\\D.T.png\" />");

    textEdit.move(20, 270);
    textEdit.resize(560, 130);
    textEdit.insertPlainText("QTextEdit");
    textEdit.insertPlainText("\n"); // �� html �� "\n" ��������
    //textEdit.insertPlainText("<img src=\"C:\\Users\\hp\\Desktop\\D.T.png\" />");
    textEdit.insertHtml("<img src=\":/res/D.T.png\" />");
}

MainWindow::~MainWindow()
{
    
}
