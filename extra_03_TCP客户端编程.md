# TCP 客户端编程
- Qt中的TCP客户端编程
    ![](_v_images_/.png)

-  Qt中的TCP客户端编程
    - 对于Qt编程而言，网络只是数据传输的通道
    - Qt提供了 QTcpSocket类（封装了 TCP协议细节）
    - 将QTcpSocket的对象当作黑盒使用，进行数据收发

    ![](_v_images_/.png)

-  QTcpSocket的使用方式
    1. 连接服务端主机 ( connectToHost() )
    2. 发送数据/接收数据（ write() / read() )
    3. 关闭连接（ close() )

-  QTcpSocket的注意事项
    - 默认情况下，QTcpSocket使用异步编程的方式
        - 操作完成后立即返回
        - 通过发送信号的方式返回操作结果
    - QTcpSocket提供了辅助函数，可完成同步编程的方式
        - waitForConnected() / waitForDisconnected()
        - waitForBytesWritten() / waitForReadyRead()

-  QTcpSocket的同步编程
    ![](_v_images_/.png)

# 编程实验 QTcpSocket 同步编程

-  QTcpSocket的异步编程
    - QTcpSocket对象通过发送信号的方式返回操作结果
    - 可以在程序中将对应信号连接到槽函数，获取结果
    - 在GUI应用程序中通常使用QTcpSocket的异步方式

-  QTcpSocket中的关键信号
    - connected() : 成功连接远端主机
    - disconnected() : 远端主机断开连接
    - readyRead() : 远端数据到达本机
    - bytesWritten(qint64) : 数据成功发送至系统（OS)

# 编程实验 QTcpSocket 异步编程

# 小结
- Qt提供了 QTcpSocket类，其对象可用于收发TCP数据
- QTcpSocket默认使用异步编程的方式
- QTcpSocket提供了辅助函数，可完成同步编程的方式
- GUI应用程序通常使用QTcpSocket的异步编程方式
