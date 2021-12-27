# 1. Qt中的IO操作
- Qt中IO操作的处理方式
    - Qt通过<font color=red>统一的接口</font>简化了<font color=red>文件</font>与<font color=red>外部设备</font>的操作方式
    - <font color=red>Qt中的文件被看作一种特殊的外部设备</font>
    - Qt中的<font color=red>文件</font>操作与<font color=red>外部设备</font>的操作相同

    > 统一的IO操作方式，吸收了Linux中的概念, 一切皆文件

- IO操作中的关键函数接口
    - 打开设备: `bool open(OpenMode mode)`
    - 读取数据: `QByteArray read(qint64 maxSize)`
    - 写入数据: `qint64 write(const QByteArray &byteArray)`
    - 关闭设备: `void close()`

    > <font color=red>IO操作的本质：连续存储空间的数据读写</font>

- Qt中IO设备的类型
    - <font color=red>顺序存取设备</font>
        - 只能<font color=red>从头开始顺序的读写数据</font>，不能指定数据的读写位置
        > 比如连接在串口上的设备
    - <font color=red>随机存取设备</font>
        - <font color=red>可以定位到任意的位置进行数据的读写</font> ( seek function )
        > 比如文件操作

- Qt中IO设备的继承层次图
    ![](vx_images/032_1.png)
    > 所有IO目标都是一种IO设备，文件、网络编程、串口编程、内存操作，均是IO设备。
    > `QBuffer`指内存中一片连续的空间。
    > `QAbstractSocket`网络编程。
    > `QProcess`进程间通信的多进程编程。

# 2. Qt中的文件操作
- `QFile` 是 Qt 中用于文件操作的类
- `QFile` 对象对应到<font color=red>计算机上的一个文件</font>

    ```cpp
    QFile file("C:/Users/hp/Desktop/test.txt");

    if( file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
        file.write("D.T.Software");
        file.close();
    }

    if( file.open(QIODevice::Readonly | QIODevice::Text) ) {
        QByteArray ba = file.readAll(); /* 保存文件中的每一个字节 */
        QString s(ba); /* 用字节数组初始化字符串对象 */

        qDebug() << s;

        file.close();
    }
    ```
- `QFilelnfo`类用于读取文件属性信息

    ```c
    QFile file ("C:/Users/hp/Desktop/test.txt");
    QFileInfo info(file);

    qDebug() << info.exists();        /* 文件是否存在 */
    qDebug() << info.isFile();        /* 是文件还是文件夹 */
    qDebug() << info.isReadable();    /* 文件是否可读 */
    qDebug() << info.isWritable();    /* 文件是否可写 */
    qDebug() << info.created();       /* 当前文件是什么时候创建的 */
    qDebug() << info.lastRead();      /* 当前文件最后被访问的时间 */
    qDebug() << info.lastModified();  /* 当前文件最后被修改的时间 */
    qDebug() << info.path();          /* 文件路径 */
    qDebug() << info.fileName();      /* 文件名 */
    qDebug() << info.suffix();        /* 文件后缀 */
    qDebug() << info.size();          /* 文件大小 */
    ```

# 3. 编程实验 文件操作初体验
实验目录：[31-1](vx_attachments\032_File_operations_in_Qt\31-1)
创建控制台项目。

# 4. QTemporaryFile
- Qt中提供了临时文件操作类 `QTemporaryFile`
    - 安全地创建一个<font color=red>全局唯一</font>的临时文件
    - <font color=red>当对象销毀时，对应硬盘上的临时文件也将被删除</font>
    - 临时文件的打开方式为 `QIODevice::ReadWrite`
    - 临时文件常用于<font color=red>大数据传递</font>或者<font color=red>进程间通信</font>的场合
        > 如何进行进程间通信？？？

    ![](vx_images/032_2.png)
    > - 使用场合
    > 	- 多进程间通信数据量特别大时, 比如几百兆, 不可能靠内存. 因此,  A进程写文件, B进程读文件.
    > - 为什么不使用 QFile ?
    >     - 这个文件的文件名必须全局唯一, QTemporaryFile 不用考虑文件的命名.
    >     - QTemporaryFile 保存在系统的tmp目录：`C:/Users/xxx/AppData/Local/Temp`

# 5. 编程实验 临时文件的使用
实验目录：[31-2](vx_attachments\032_File_operations_in_Qt\31-2)
创建控制台项目。

# 6. 小结
- Qt通过<font color=red>统一的方式</font>读写文件和外部设备
- Qt中IO设备的类型分为<font color=red>顺序存取</font>和<font color=red>随机存取</font>两种
- `QFile` 提供了文件操作相关的方法
- `QFilelnfo` 提供了读取文件属性相关的方法
- Qt中提供了临时文件操作类 `QTemporaryFile`