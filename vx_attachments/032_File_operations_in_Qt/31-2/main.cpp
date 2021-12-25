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

    qDebug() << "isFile   : " << info.isFile();
    qDebug() << "path     : " << info.path();
    qDebug() << "fileName : " << info.fileName();
    
    return a.exec();
}
