Test:简单测试工程
Calculator:计算器工程,添加按钮的消息处理

1. 信号与槽
    Qt 中定义了与系统消息相关的概念, Qt 为了做到真正的跨平台,摒弃了一些具体的操作系统平台上面关于用户消息及消息处理函数的概念,完全不用现成的操作系统中的概念,另起炉灶,有了自己的一套概念
    - 信号(Signal)
        由操作系统产生的消息
    - 槽(Slot)
        程序中的消息处理函数
    - 连接(Connect)
        将系统消息绑定到消息处理函数
        
    QObject_1 发送信号 emit signal -> connect -> QObject_2 消息处理函数 slot function
    信号与槽的连接必须发生在两个Qt类对象之间!

2. Qt 的核心 - QObject::connect 函数
    bool connect(const QObject *sender,     // 发送对象
                 const char *signal,        // 消息名
                 const QObject *receive,    // 接收对象
                 const char *method,        // 接收对象的成员函数
                 QT::ConnectionType type = Qt::AutoConnection);

    Note:
    - 在Qt中,消息用字符串进行描述
    - connect函数在消息名和处理函数之间建立映射
    
3. 相对c++, Qt 中的"新"关键字
    - SIGNAL
        用于指定消息名
    - SLOT
        用于指定消息处理函数名
    - Q_OBJECT
        所有自定义槽的类必须在类声明的开始处加上 Q_OBJECT
    - slots
        用于在类中声明消息处理函数

4. 自定义槽
    - 只有 QObject 的子类才能自定义槽
    - 定义槽的类必须在声明的最开始处使用 Q_OBJECT
    - 类中声明槽时需要使用 slots 关键字
    - 槽与所处理的信号在函数签名上必须一致 // 信号的名字其实是函数的签名,也就是信号函数和定义的信号处理函数的形参要保证完全一致
    - SIGNAL 和 SLOT 所指定的名称中:
        可以包含参数类型
        不能包含具体的参数名

5. 添加信号与槽相关内容后,代码编译错误,重新构建所有项目依然错误,需执行qmake重新生成Makefile编译
后面深入讲解信号与槽时解释,这个与QT平台本身的实现机制相关

6. qDebug()出现无法获取调试输出时,可能是开了多个QT工程,关闭其他工程即可

7. sender函数,查看帮助
QPushButton *btn = (QPushButton*)sender(); // 得到被点击的按钮指针

8. 经典问题解决 : Object::connect:No such slot ...
    - 检查类是否继承于 QObject
    - 检查类声明的开始处是否添加 Q_OBJECT
    - 检查是否使用 slots 关键字进行槽声明
    - 检查槽的名称是否拼写错误
    - 重新执行 qmake


.test
    创建项目 -> QT控件项目 -> Qt Gui应用 -> 下一步 -> 下一步 -> 基类:QWidget, 取消勾选创建界面