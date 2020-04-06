#include "Widget.h"
#include <QPainter>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <QApplication>
#include <QDesktopWidget>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_loadBtn.setParent(this);
    m_loadBtn.move(10, 10);
    m_loadBtn.resize(70, 30);
    m_loadBtn.setText("Load");

    m_grabBtn.setParent(this);
    m_grabBtn.move(90, 10);
    m_grabBtn.resize(70, 30);
    m_grabBtn.setText("Grab");

    resize(500, 350);

    connect(&m_loadBtn, SIGNAL(clicked()), this, SLOT(onLoadBtnClicked()));
    connect(&m_grabBtn, SIGNAL(clicked()), this, SLOT(onGrabBtnClicked()));
}

void Widget::onLoadBtnClicked()
{
    QFileDialog fd(this);

    fd.setAcceptMode(QFileDialog::AcceptOpen);
    fd.setFileMode(QFileDialog::ExistingFile);

    if( fd.exec() == QFileDialog::Accepted )
    {
        QImage img;

        if( img.load(fd.selectedFiles()[0]) )
        {
            m_pmap = QPixmap::fromImage(img);

            update();
        }
        else
        {
            QMessageBox(QMessageBox::Critical, "Error", "Invalid image file!").exec();
        }
    }
}

void Widget::onGrabBtnClicked()
{
    m_pmap = QPixmap::grabWindow(QApplication::desktop()->winId());

    update();
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;

    if( !m_pmap.isNull() )
    {
        painter.begin(this);
        painter.drawPixmap(0, 0, width(), height(), m_pmap);
        painter.end();
    }
}

Widget::~Widget()
{
    
}
