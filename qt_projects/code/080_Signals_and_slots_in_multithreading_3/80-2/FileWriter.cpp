#include "FileWriter.h"
#include <QDebug>

void FileWriter::Worker::run()
{
    qDebug() << "void FileWriter::Worker::run() - begin: tid = " << currentThreadId();

    exec();

    qDebug() << "void FileWriter::Worker::run() - end";
}

FileWriter::FileWriter(QString file, QObject *parent) :
    QObject(parent), m_file(file)
{
    connect(this, SIGNAL(doWrite(QString)), this, SLOT(writeSlot(QString)));
    connect(this, SIGNAL(doClose()), this, SLOT(closeSlot()));

    moveToThread(&m_worker);

    m_worker.start();
}

bool FileWriter::open()
{
    return m_file.open(QIODevice::WriteOnly | QIODevice::Text);
}

void FileWriter::write(QString text)
{
    qDebug() << "void FileWriter::write(QString text) tid = " << QThread::currentThreadId();

    emit doWrite(text);
}

void FileWriter::close()
{
    qDebug() << "void FileWriter::close() tid = " << QThread::currentThreadId();

    emit doClose();
}

void FileWriter::writeSlot(QString text)
{
    qDebug() << "void FileWriter::writeSlot(QString text) tid = " << QThread::currentThreadId();

    m_file.write(text.toAscii());
    m_file.flush();
}

void FileWriter::closeSlot()
{
    qDebug() << "void FileWriter::closeSlot() tid = " << QThread::currentThreadId();

    m_file.close();
}

FileWriter::~FileWriter()
{
    m_worker.quit();
}
