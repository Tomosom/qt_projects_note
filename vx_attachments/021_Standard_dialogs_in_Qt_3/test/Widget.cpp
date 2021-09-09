#include "Widget.h"
#include <QDebug>
#include <QPrinter>
#include <QTextDocument>
#include <QPrintDialog>
#include <QProgressDialog>
#include <QFontDialog>

Widget::Widget(QWidget *parent) : QWidget(parent),
    FontDialogBtn(this), ProgressDialogBtn(this), PrintDialogBtn(this)
{
    FontDialogBtn.setText("Font Dialog");
    FontDialogBtn.move(20, 20);
    FontDialogBtn.resize(160, 30);

    ProgressDialogBtn.setText("Progress Dialog");
    ProgressDialogBtn.move(20, 70);
    ProgressDialogBtn.resize(160, 30);

    PrintDialogBtn.setText("Print Dialog");
    PrintDialogBtn.move(20, 120);
    PrintDialogBtn.resize(160, 30);

    resize(200, 170);
    setFixedSize(200, 170);

    connect(&FontDialogBtn, SIGNAL(clicked()), this, SLOT(FontDialogBtn_Clicked()));
    connect(&ProgressDialogBtn, SIGNAL(clicked()), this, SLOT(ProgressDialogBtn_Clicked()));
    connect(&PrintDialogBtn, SIGNAL(clicked()), this, SLOT(PrintDialogBtn_Clicked()));
}

void Widget::FontDialogBtn_Clicked()
{
    QFontDialog dlg(this);

    dlg.setWindowTitle("Font Dialog Test");
    dlg.setCurrentFont(QFont("Courier New", 10, QFont::Bold));

    if( dlg.exec() == QFontDialog::Accepted )
    {
        qDebug() << dlg.selectedFont();
    }
}

void Widget::ProgressDialogBtn_Clicked()
{
    QProgressDialog dlg(this);

    dlg.setWindowTitle("Updating...");
    dlg.setLabelText("Downloading update from server...");
    dlg.setMinimum(0);
    dlg.setMaximum(100);
    dlg.setValue(35);

    // create a new thread

    dlg.exec();
}

void Widget::PrintDialogBtn_Clicked()
{
    QPrintDialog dlg(this);

    dlg.setWindowTitle("Print Dialog Test");

    if( dlg.exec() == QPrintDialog::Accepted )
    {
        QPrinter* p = dlg.printer();
        QTextDocument td;

        //td.setPlainText("Printer object test!");
        td.setHtml("<h1>Print html object test</hl>"); // h1在html中表示字体大写

        //p->setOutputFileName("D:\\test.xps");
        p->setOutputFileName("D:\\test.pdf");

        td.print(p);
    }
}

Widget::~Widget()
{
    
}
