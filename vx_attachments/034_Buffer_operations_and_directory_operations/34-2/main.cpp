#include <QtCore/QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDebug>

void test_dir()
{
    const char *PATH = "./QDir";
    QDir dir;

    if (!dir.exists(PATH)) {
        dir.mkdir(PATH);
    }

    if (dir.exists(PATH)) {
        dir.cd(PATH);

        QStringList list = dir.entryList();

        /* 会打印当前目录:'.', 和上级目录:'..' */
        for (int i = 0; i < list.count(); i++) {
            qDebug() << list[i];
        }
    }
}

/* 计算文件或目录大小 */
unsigned int calculate_size(QString path)
{
    QFileInfo info(path);
    unsigned int ret = 0;

    if (info.isFile()) {
        ret = info.size();
    } else if (info.isDir()) {
        QDir dir(path); /* 生成文件夹对象 */

#if 0
        /* 当目录中含有多层目录，打印的结果会不正确 */
        QStringList list = dir.entryList();
        for (int i = 0; i < list.count(); i++) {
            if ((list[i] != ".") && (list[i] != "..")) {
                qDebug() << list[i]; /* bug原因：entryList()仅仅取到的是条目, 不是绝对路径，因此无法使用递归 */
                ret += calculate_size(list[i]); /* 递归 */
            }
        }
#else
        /* 修正 */
        QFileInfoList list = dir.entryInfoList();
        for (int i = 0; i < list.count(); i++) {
            if ((list[i].fileName() != ".") && (list[i].fileName() != "..")) {
                qDebug() << list[i].absoluteFilePath(); /* 取绝对路径，方便递归 */
                ret += calculate_size(list[i].absoluteFilePath());
            }
        }
#endif
    }

    return ret;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    test_dir();
    qDebug() << calculate_size("./QDir");

    return a.exec();
}
