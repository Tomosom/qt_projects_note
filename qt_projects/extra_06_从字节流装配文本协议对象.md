从字节流装配文本协议对象


- 问题
如何将接收缓冲区中的数据装配成为协议对象？


- 深度思考
-数据是否能够装配成为协议对象？
•数据量足够
，如果数据量足够，是否能够装配不止4对象？
y如何处理剩余数据（属于下4协议对象）？
•数据量不足
^是否达到协议最小随（8字节）？
Z如何处理数据量超过最小长度，但不足以产生4对象的情况？


- 初步的解决方案
-定义一个类用于接收字节流并装配协议对象
-类中提供容器（队列）暂存字节流
-当容器中至少存在8个字节时开始装配
1. 首先装配协议中的类型（type)和数据区长度（length)
2. 根据数据区长度从容器中取数据装配协议数据（data)
3. 当协议数据装配完成时，创建协议对象并返回，否则，返回NULL


- 协议对象装配类的初步设计


编程实验 装配类的初步设计class TxtMsgAssembler;


-  assembleQ函数的实现流程
〇


-  assemble〇函数的注意事项
-以retype作为标志决定是否解析类型和长度
-mjength是接收后续数据的基础
-当m data的长度与mjength相同时创建协议对象
-否则，返回NULL


-  makeTypeAndLength〇 实现要点
-条件：容器中至少有8字节数据
• mtype = fetch(4);
• mjength = tolnt( fetch(4), 16 );
•当长度转换成功时，可创建对象（makeMessageQ)


-  makeMessage〇 实现要点
int needed = m_length - m_data.length(); // 计算需要的剩余数据量
int n = (needed <= m_queue.length〇) ? needed : m_queue.length();
m_data += fetch(n); //从容器中取n个字节进行追加
if( m一length == m_data.length())
{
return TextMessage(m_type, m一data);


编程实验


小结
装配类的最终完善class TxtMsgAssembler;
- 从连续字节流装配协议对象是应用自定义协议的基础
- 装配类（ TxtMsgAssembler)用于解析自定义协议
- 装配类的实现的关键是如何处理字节数据不够的情况
- 自定义协议类和装配类能够有效解决数据粘连问题
------------------------^
TextMessage
TxtMsgAssembler
+ type(): QString
+ length(): int
+ data(): QString
+ serialize(): QString
+ unserialize(s : QString): boolean
+ prepare(data : const char*, len : int): void
+ assemble(): TextMessage*
+ reset(): void