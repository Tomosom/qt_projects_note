# 1. 文本协议的网络应用
- 将TextMessage对象作为网络传输的基本单位
    ![](_v_images_/.png)
    ```c
    TextMessage message("Demo", "狄泰软件学院！"）；
    ClientDemo client;

    client.connectTo("127.0.0.1", 8890);
    client.send(message);
    ```

- 架构设计
    ![](_v_images_/.png)

- 实现概要
    - 客户端提供发送 TextMessage 对象的成员函数
    - 客户端和服务端均内置 TxtMsgAssembler 对象
        - 用于从网络字节流装配 TextMessage 对象
    - 当成功收到 TextMessage 对象
        - 使用 TxtMsgHandler 接口进行异步通知

# 2. 编程实验 文本协议网络应用实现初步
实验目录：[xxx](vx_attachments\xxx)

- 存在的问题
    服务端无法正确接收多个客户端的 TextMessage 消息！！ ！

- 解决方案初步
    为每一个与客户端通信的TcpSocket对象分配一个专用的装配对象！！
    ![](_v_images_/.png)

-  Qt中的QMap容器
    - QMap是一种基于键值对（Key-Value)的字典数据结构
    - QMap是通过模板定义的，键和值都可以是自定义数据类型
    - QMap使用示例：

    ```c
    QMap<QString, int> map;
    map["one"] = 1;
    map["three"] = 3;
    map["seven"] = 7;

    map.insert("twelve", 12);

    int num1 = map["thirteen"];
    int num2 = map.value("thirteen");
    ```

- 解决方案
    - 客户端连接至时，动态创建装配对象，插入字典中
    - 网络字节流到达时，在字典中查找对織配对象
    - 通过查找到的装配对象处理字节流
    - 客户端断开时，销毁对应的装配对象

# 3. 编程实验 文本协议网络应用服务端优化
实验目录：[xxx](vx_attachments\xxx)

# 4. 小结
- 使用文本协议的网络应用，收发都基于TextMessage对象
- 定义TxtMsgHandler接口进行文本协议对象的异步接收
- 服务端需要为每个连接分配—个TxtMsgAssembler对象
- QMap容器是一种基于键值对（Key-Value)的数据结构
