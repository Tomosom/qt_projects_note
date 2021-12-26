# 1. 缓冲区操作

- Qt中缓冲区的概念
    - 缓冲区的本质为<font color=red>一段连续的存储空间</font>
    - `QBuffer` 是Qt中缓冲区相关的类
    - 在Qt中可以将缓冲区看作<font color=red>一种特殊的IO设备</font>
        > 可以使用[032_QFile-QFileInfo-QTemporaryFile](032_QFile-QFileInfo-QTemporaryFile.md)中的4个经典IO步骤一段内存空间。
    - 文件流辅助类([033_QTextStream-QDataStream](033_QTextStream-QDataStream.md))可以<font color=red>直接用于操作缓冲区</font>

- `QBuffer`缓冲区的使用方式
    ```cpp
    QByteArray array;
    QBuffer buffer(&array);

    if (buffer.open(QIODevice::WriteOnly)) {
        QDataStream out(&buffer);
        out << QString ("D.T.Software");
        out << 3.14;
        buffer.close();
    }
    ```

- `QBuffer`缓冲区的使用场合
    1. 在线程间进行不同类型的<font color=red>数据传递</font>
    2. 缓存<font color=red>外部设备</font>中的数据返回
    3. <font color=red>数据读取速度小于数据写入速度</font>

    > 均涉及到数据的读写操作

# 2. 编程实验 缓冲区操作
实验目录：[34-1](vx_attachments\034_Buffer_operations_and_directory_operations\34-1)
创建控制台程序。

# 3. 目录操作
- `QDir` 是Qt中功能强大的目录操作类
    - Qt 中的目录分隔符统一使用 <font color=red>'/'</font>
    - `QDir` 能够对目录<font color=red>进行任意操作</font>（创建，删除，重命名）
    - `QDir` 能够<font color=red>获取指定目录中的所有条目</font>（文件和文件夹）
    - `QDir` 能够<font color=red>使用过滤字符串</font>获取指定条目
    - `QDir` 能够获取系统中的<font color=red>所有根目录</font>

- 目录操作基础示例

```cpp
const char* PATH = "C:/Users/hp/Desktop/QDir";
QDir dir;
if (!dir.exists(PATH)) {
    dir.mkdir(PATH);
}
if (dir.exists(PATH)) {
    dir.cd(PATH);
    QStringList list = dir.entryList();
    for (int i=0; i < list.count(); i++) {
        /* Dir Operation */
    }
}
```

# 4. 编程实验 目录操作示例
实验目录：[34-2](vx_attachments\034_Buffer_operations_and_directory_operations\34-2)
创建控制台程序。
随便拷贝些东西到创建的QDir目录，以进行实验。

# 5. 文件系统监视器
- `QFileSystemWatcher` 用于监控文件和目录的状态变化
    - <font color=red>能够监控特定目录和文件的状态</font>
    - 能够同时对<font color=red>多个目录和文件</font>进行监控
    - 当目录或者文件<font color=red>发生改变时将触发信号</font>
    - 可以<font color=red>通过信号与槽的机制</font>捕捉信号并做出响应
    > 状态变化 : 文件内容, 重命名, 删除
    > 目录中添加文件, 是否算目录状态变化 ? 答案 : 会

- 文件监控示例

```cpp
/* 1.定义槽函数，监控状态变化 */
void Watcher::statusChanged(const QString &path)
{
    /* do something for the status change */
}
/* 2.连接状态信号到槽函数 */
Watcher::Watcher(QObject *parent) : QObject(parent)
{
    connect(&m_watcher, SIGNAL(fileChanged(const QString&)), ...);
    connect(&m_watcher, SIGNAL(directoryChanged(const QString&)), ...);
}
/* 3.加入受监控的文件或者目录 */
void Watcher::addPath(QString path)
{
    m_watcher.addPath(path);
}
```

# 6. 编程实验 文件监控示例
实验目录：[34-3](vx_attachments\034_Buffer_operations_and_directory_operations\34-3)
创建控制台程序。
当前目录创建要监听的文件text.txt和目录QDir，以进行实验。

注：涉及信号与槽必然要继承 `QObject` 类
更多查看 `QFileSystemWatcher` 帮助文档

# 7. 小结
- 缓冲区的本质为<font color=red>一段连续的内存空间</font>
- 在Qt中可以将缓冲区 `QBuffer` 看作一种特殊的IO设备
- `QDir` 提供了强大的目录操作支持
	> 通过此类可自行实现一个文件浏览器
- `QFileSystemWatcher` 能够监控文件和目录的状态变化
