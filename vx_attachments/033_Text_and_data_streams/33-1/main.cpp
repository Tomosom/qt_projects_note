#include <QtCore/QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //QFile file("C:/Users/hp/Desktop/test.hex");
    QFile file("test.hex");

    /* û�м� QIODevice::Text ��ʾ���ֽ����ķ�ʽ���ļ� */
    if( file.open(QIODevice::WriteOnly) )
    {
        QString dt = "D.T.Software";
        double value = 3.14;

        /* ʹ��QFile�������ݻ��ı��Ķ�д�ǿ��е�,�˴�Ϊ������ĵط�-����ת�� */
        file.write(dt.toStdString().c_str()); // ��QString����תΪֱ�ӵĶ���������
        file.write(reinterpret_cast<char*>(&value), sizeof(value)); // ����ת��Ϊ�ֽ����͵�����

        file.close();
    }

    if( file.open(QIODevice::ReadOnly) )
    {
        QString dt = "";
        double value = 0;

        dt = QString(file.read(12)); /* "D.T.Software" */
        file.read(reinterpret_cast<char*>(&value), sizeof(value));

        file.close();

        qDebug() << dt;
        qDebug() << value;
    }
    
    return a.exec();
}
