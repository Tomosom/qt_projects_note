# 1. 对话框的概念
- <font color=red>对话框</font>是与用户进行<font color=red>简短交互</font>的<font color=red>顶层</font>窗口
- `QDialog`是Qt中所有对话框<font color=red>窗口的基类</font>
- `QDialog`继承于`QWidget`是一种<font color=red>容器类型</font>的组件
    ![](vx_images/017_1.png)

- `QDialog`的意义 (有了`QWidget`为什么还要有`QDialog`?)
    - `QDialog`作为一种<font color=red>专用的交互窗口</font>而存在
    - `QDialog`<font color=red>不能</font>作为子部件嵌入其它容器中
        > `QWidget`若有父组件，将作为一个可见的部件被嵌入到父组件中
    - `QDialog`是<font color=red>定制了窗口式样</font>的<font color=red>特殊的QWidget</font>

# 2. 编程实验 QDialog 和 QWidget 的区别
实验目录：[Test](vx_attachments\017_Dialogs_and_their_types\Test)
代码：main.cpp, 实验一

# 3. 对话框的类型
## 3.1. 类型
- <font color=red>模态</font>对话框(`QDialog::exec()`)
    - 显示后<font color=red>无法与父窗口进行交互</font>
    - 是一种<font color=red>阻塞式</font>的对话框调用方式
- <font color=red>非模态</font>对话框(`QDialog::show()`)
    - 显示后<font color=red>独立存在</font>可以<font color=red>同时与父窗口进行交互</font>
    - 是一种<font color=red>非阻塞式</font>的对话框调用方式

## 3.2. 应用场合
- 一般情况下
    - <font color=red>模态</font>对话框用于<font color=red>必须依赖用户选择的场合</font>(出场率：80%)
        - 消息提示，文件选择，打印设置，等
    - <font color=red>非模态</font>对话框用于<font color=red>特殊功能设置的场合</font>(出场率：20%)
        - 查找操作，属性设置，等
- 小技巧
    - 在<font color=red>栈</font>上创建<font color=red>模态对话框</font>是最简单常用的方式
    - 一般情况下<font color=red>非模态对话框</font>需要在<font color=red>堆</font>上创建
    - 通过`QDialog::setModal`函数可以创建<font color=red>混合特性</font>的对话框
        > 综合了非模态对话框和模态对话框的特性，在运行机理上是非模态对话框的特性，在表现形式上是模态对话框的特性。
    - <font color=red>非模态对话框</font>需要指定`Qt::WA_DeleteOnClose`属性
        > 关闭对话框的时候，同时删除对话框对象

# 4. 编程实验不同特性的对话框
实验目录：[Test](vx_attachments\017_Dialogs_and_their_types\Test)
代码：main.cpp, 实验二

# 5. 对话框的返值
- 只有<font color=red>模态对话框</font>才有<font color=red>返回值</font>的概念
    > 因模态对话框是需要用户进行选择的
- 模态对话框的<font color=red>返回值</font>用于<font color=red>表示交互结果</font>
- `QDialog::exec()`的返回值为交互结果
    - `void QDialog::done(int i)`关闭对话框并将参数作为交互结果
    - `QDialog::Accepted` - 用户操作成功
    - `QDialog::Rejected` - 用户操作失败

# 6. 编程实验对话框的返回值
实验目录：[Test](vx_attachments\017_Dialogs_and_their_types\Test)
代码：main.cpp, 实验三

# 7. 小结
- 对话框分为<font color=red>模态对话框</font>和<font color=red>非模态对话框</font>
- <font color=red>模态对话框是阻塞式的</font>
- 模态对话框用于<font color=red>依赖用户交互结果的场合</font>
- <font color=red>非模态对话框是非阻塞式的</font>
- 非模态对话框用于<font color=red>功能设置的场合</font>
