# TCP服务端编程
- 网络中的服务端
    服务端是为客户端服务的，服务的内容诸如向客户端提供资源，保存客户端数据，为客户端提供功能接口，等。

- 问题
    经常听说的 C/S 网络结构是什么?

- Client / Server 软件架构简介
    ![](_v_images_/.png)

- Client / Server软件架构的特点
    - 服务端被动接受连接（服务端无法主动连接客户端）
    - 服务端必须公开网络地址（容易受到攻击）
    - 在职责上
        - 客户端倾向于处理用户交互及体验（GUI)
        - 服务端倾向于用户数据的组织和存储（数据处理）

- 扩展小知识
    B/S 网络结构又是什么？和C/S网络结构有什么不同？

-  Browser / Server 软件架构简介（B/S)
    - B/S 是一种特殊的 C/S 网络架构
    - B/S 中的客户端统一使用浏览器（Browser)
    - B/S 中的客户端GUI通常采用HTML进行开发
    - B/S 中的客户端与服务端通常采用http协议进行通信

-  Qt中的TCP服务端编程
    ![](_v_images_/.png)

- Qt中的TCP服务端编程
    - Qt提供了 QTcpServer类（封装了 TCP协议细节）
    - 将QTcpServer的对象当作黑盒使用，进行连接监听
    - 每一个连接生成一个QTcpSocket对象进行通信

    ![](_v_images_/.png)

-  QTcpServer的使用方式
    1. 监听本机地址的端口（ listen() )
    2. 通过信号通知客户端连接（ newConnection() )
    3. 获取 QTcpSocket通信对象（ nextPendingConnection() )
    4. 停止监听（ close() )

- QTcpServer的注意事项
    - 用于处理客户端连接，不进行具体通信
    - 监听的端口只用于响应连接请求
    - 监听到连接后，生成QTcpSocket对象与客户端通信

-  Client/Server 交互流程
    ![](_v_images_/.png)

# 编程实验 QServerSocket 编程示例

# 小结
- 服务端是为客户端提供功能服务，被动的接受连接
- Qt提供了 QTcpServer 类，用于端口的连接监听
- 监听到连接后，生成 QTcpSocket 对象与客户端通信
- 每个 QTcpSocket 对象同样需要连接信号到槽函数
