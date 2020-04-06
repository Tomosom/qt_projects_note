#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QObject>
#include <QFile>
#include <QThread>

class FileWriter : public QObject
{
    Q_OBJECT

    class Worker : public QThread
    {
    protected:
        void run();
    };

    QFile m_file;
    Worker m_worker;
public:
    explicit FileWriter(QString file, QObject *parent = 0);
    bool open();
    void write(QString text);
    void close();
    ~FileWriter();
signals:
    void doWrite(QString text);
    void doClose();
protected slots:
    void writeSlot(QString text);
    void closeSlot();
};

#endif // FILEWRITER_H
