#include <QtCore/QCoreApplication>
#include <QTemporaryFile>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTemporaryFile tempFile;

    if( tempFile.open() )
    {
        tempFile.write("D.T.Software");
        tempFile.close();
    }

    QFileInfo info(tempFile);

    qDebug() << info.isFile();
    qDebug() << info.path();
    qDebug() << info.fileName();
    
    return a.exec();
}
