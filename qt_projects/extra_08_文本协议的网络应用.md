文本协议的网络应用
- 将TextMessage对象作为网络传输的基本单位
客户端 服务端
TextMessage message("Demo","狄泰软件学院！"）；
ClientDemo client;
client.connectTo("127.0.0.1", 8890);
client.send(message);
- 架构设计
- 实现概要
-客户端提供发送TextMessage对象的成员函数
-客户端和服务端均内置TxtMsgAssembler对象
•用于从网络字节流装配TextMessage对象
-当成功收到TextMessage对象
•使用TxtMsgHandler接口进行异步通知
编程实验 文本协议网络应用实现初步
- 存在的问题
月艮务端无法正确接收多个客户端的
TextMessage 消息！！ ！
- 解决方案初步
为每一^与客户端通信的TcpSocket对象
分配1专用的装配对象！！
QMap
tcpSocket 一 1 -------------► txtMsgAssembler_l
tcpSocket_n ------------------► txtMsgAssembler_n
-  Qt中的QMap容器
_ QMap是一种基于键值对（Key-Value)的字典数据结构
_ QMap是通过模板定义的，键和值都可以是自定义謝居类型
-QMap使用示例：
QMap<QString, int> map;
map[’_one"] = 1;
map["three"] = 3;
map[’_seven"] = 7;
map.insert("twelve", 12);
int numl = map["thirteen"];
int num2 = map.value("thirteen");
- 解决方案
-客户端连接至时，动态创建装配对象，插入字典中
-网络字节流到达时，在字典中查找对織配对象
-通过查找到的装配对象处理字节流
_客户端断开时，销毁对应的装配对象
编程实验 文本协议网络应用服务端优化
小结
- 使用文本协议的网络应用，收发都基于TextMessage对象
- 定义TxtMsgHandler接口进行文本协议对象的异步接收
- 服务端需要为每个连接分配—个TxtMsgAssembler对象
-  QMap容器是一种基于键值对（Key-Value)的数据结构