私聊模式的设计与实现
■问题
如何实现聊天室中的私聊模式?
■私聊模式：用户在聊天时能够指定消息的接收者
■ 聊天界面的改动
狄泰聊天室
消息接收区域
□用户-1
□用户-2
□用户-3 、
用户名
消悤输入区域 I
状态：總录 登录 发送
1. 增加在线聊天用户列表
2. 实现私聊用户选择的功能
■ Qt中的列表类QListWidget
QListWidget* lw = new QListWidget(this);
QListWidgetltem* item = NULLj
item = new QListWidgetItem();
item->setText("item 1");
item->setCheckState(Qt::Unchecked);
lw->addltem(item);
item = new QListWidgetItem();
item->setText("item 2");
item->setCheckState(Qt::Checked);
lw->addltem(item);
□ item 1
0 item 2
QListWidget
■ USER消息设计
-新增USER消息，用于传输当前的磁用户
-USER消息数据区格式：ID-1\rlD-2\r…
-在有用户登录或退出的时，服务端主动发送USER消息
-USER消息的的目标接收者为所有在线客户端
编程实验 在线用户列表
■ MSGP消息设计
-新增MSGP消息，用于传输私聊消息
-MSGP 消息数据区格式：ID-1\rlD-2\r."msg\r
-月艮务端接收到MSGP消息后
•解析出目标客户端（ID)和私聊文本（text)
•使用 text 构造 MSGA 消息（TextMessage tm("MSGA", text);)
•将tm发送给由MSGP中ID指定的目标客户端
■ MSGP消息处理函数的实现
QStringList tl = message.data().splitC'Xr", QString::SkipEmptyParts);
const QByteArray& ba = TextMessage("MSGA", tl.last〇) .serialize();
tl.removeLast();
for(int i=0; i<tl.length(); i++)
{
for(int j=0; j<m_nodeList.length(); j++)
{
Node* n = m_nodeList.at(j);
if( (tl[i] == n->id) && (n->socket != NULL))
{
n-> socket->wr ite(ba);
break;
}
■实现中需要注意的问题
-区分发送的是公聊消息还是私聊消息
•当用列表中的用户被勾选，发送私聊消息，否则发送公聊消息
•私聊消息的目标客户端必须包含发送者自身
编程实验 私聊模式的实现
实战预告
■ To be continued ...
思考：
•如何定义聊天室管理员这个角色？
•如何区分管理员和普通聊天用户？
•如何实现管理员所具备的功能？