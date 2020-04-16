从字节流装配文本协议对象
■问题
文本协议的设计与实现能够支持中文吗?
文本协议的中文处理
■回顾协议设计
数麟型 数据区
l 里里 1
1
4个字符
i
4个字符
1
n个字符油数据长度标识）
数据区存储的是文本字符（QString),因此，从设计的角
度，只要Qt字符串支持中文，文本协议的实现就支持中文。
■下面的代码有相同的输出吗？
TextMessage message("Demo","狄泰软件学院！"）：
QString d = message.serialize();
方式—
TextMessage unknown;
unknown.unserialize(d);
qDebug() « unknown.type();
qDebug() « unknown.length();
qDebug() « unknown.data();
TxtMsgAssembler as;
QSharedPointer<TextMessage> p;
p = as.d5semble(
d.toStdString().c_str(),
d.length()
)；
qDebug() « p->type();
qDebug() « p->length();
qDebug() « p->data();
编程实验 中文支持验证
■深度分析
文本协议的实现只考虑了 ASCII码的情况，对于中文类
型的宽字符编码情况并未考虑（宽字符>=2字节）。
■协议设计的微小改动
-Type: 4 个 ASCII 字符
- Lenqth: 4个ASCII字符（存储数据区字节数）
一数据区：使用UTF-8方式进行编码
ASCII编码
1
UTF-8编码
里 1
数麟型 数据区
i I I I
( ( (
4个字节 4个字节 n字节油数据长度标识）
■编码小知识
-ASCII
•最早的统一编码标准，规定了 128个字符编码（0-127)
-Unicode
•—个很大的字符集，规定了字符的二进制代码（编码标准）
-UTF- 8
•使用最广泛的一种Unicode编码标准的实现
■编码小知识
- UTF-8编码的特点
•一种变长的编码方式，它可以使用1-4个字节表示一个字符
•对于单字节的字符，字节的第一位设为0,后面7位为这个字符的Unicode码
•英语字母，UTF-8编码和ASCII码是相同的
•对于n字节的字符（n > 1),第一^字节的前n位都设为1,第n + 1位设为
0,后面字节的前两位一律设为10,其余二进制位，«A这个字符的Unicode
码
■ UTF-8编码示例
-"唐〃+Unicode (0x5510) + 101010100010000
-UTF-8 编码需要 3 字节 + 1110xxxx 10xxxxxx 10xxxxxx
-在X位置处依次填入Unicode编码值
• 11100101 10010100 10010000 + 0xE59490
■协议实现的改动
一 TextMessage //对象与字节流直接转换
• QByteArray serialize();
• bool unserialize(QByteArray ba);
一 TxtMsgAssembler //以字节为单位进行装配
• QByteArray fetch(intn);
编程实验 文本协议的中文支持
小结
■文本协议在实现时只考虑了 ASCII码的情况，不支持中文
■实现时可以通过对数据区进行UTF-8编码实现中文支持
■ UTF-8是Unicode编码的一种工程实现
■ UTF-8是一种变长编码，使用1 - 4个字节表示一个字符
class TextMessage;
class TxtMsgAssembler;