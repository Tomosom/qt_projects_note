# 1. 自定义事件对象
- 可以自定义新的事件类
    - 自定义的事件类<font color=red>必须继承自</font> `QEvent`，以便QT平台识别
    - 自定义的事件类<font color=red>必须拥有全局唯一的 Type 值</font>（全局唯一的ID）
    	> 不同的事件类对象，调用`type()`这个成员函数得到的值是不相同的，这个不同的值必须全局唯一。
    - <font color=red>程序中必须提供处理自定义事件对象的方法</font>
    	> 当你自定义了一个新的事件类，对于现有的QT平台不知道如何处理，QT平台只知道如何处理预定义的事件类对象，对于程序员自己定义的事件类对象而言，QT平台肯定不知道如何处理，QT平台对于无法处理的事件，会直接丢弃掉。因此，当你自定义了一个新的事件类，你必须提供处理方法。

- 自定义事件类
    1. 将`QEvent`作为父类继承
    2. 指定全局唯一的 `Type` 值
    ```cpp
    class StringEvent:public QEvent // 公有继承 QEvent
    {
    public:
        // 定义一个全局唯一的ID值
        // 在QT平台里边提供了一个枚举常量QEvent::User，这个枚举常量之前的每一个值都表示一个预定义的QT事件类
        // 我们能用的就是这个枚举常量之后的值
        static const Type TYPE = static_cast<Type>(QEvent::User + OxFF);
        // ...
    };
    ```

- Qt中事件的 `Type` 值
    - 每个事件类都拥有<font color=red>全局唯一</font>的 Type 值
    - 自定义事件类的 Type 值<font color=red>也需要自定义</font>
    - 自定义事件类使用 `QEvent::User` 之后的值作为 Type 值
    - 程序中保证 `QEvent::User + VALUE` 全局唯一即可

- 处理自定义事件对象的方法（**<font color=red>2种</font>**）
    1. 将<font color=red>事件过滤器</font>安装到目标对象
        - 在 `eventfilter()` 函数中编写自定义事件的处理逻辑
    2. 在目标对象的类中<font color=red>重写事件处理函数</font>
        - 在 `event()` 函数中编写自定义事件的处理逻辑

# 2. 编程实验 发送和处理自定义事件
实验目录：[44-1](vx_attachments\044_Sending_custom_events_2\44-1)

新建项目：Qt 控件 项目->Qt Gui 应用->基类QWidget
自定义一个事件类：添加新文件 -> c++ -> c++类（基类QEvent）

实验功能：双击主界面空白处，编辑框中插入固定字符

- <font color=red>为什么</font>要自定义事件类？
	- 需要<font color=red>扩展</font>一个已有组件类（Widget）的功能
		> 即已有的事件不足以描述这个新功能，我们要扩展Widget组件类的功能时，就需要考虑下有无必要为这个新的功能来自定义一个事件类
	- 需要开发一个<font color=red>全新功能</font>的组件类（Qt平台没有的组件类）
	- 需要向一个<font color=red>第三方的组件类</font>发送消息
		> 使用方式上可能明确地说明，你想要这个组件类干个什么事情，就需要向它发送一个我们自己定义的事件类对象 
	- 。。。

# 3. 小结
- 自定义事件类<font color=red>必须继承自</font> `QEvent`（公有继承）
- 自定义事件类使用 `QEvent::User` 之后的值作为 Type 值（这个值用于在重写的`event()`或`eventfilter()`中，被`type()`成员函数返回，来判断是哪个事件）
- 自定义事件类的 `Type` 值必须全局唯一
- <font color=red>程序中需要提供自定义事件类的处理方法</font>（`event()`或`eventfilter()`）
