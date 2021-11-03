- 完善工具栏
    ![](vx_images/029_e1.png)

# 1. 主窗口中的状态栏
- 状态栏的概念和意义
    - 状态栏是应用程序中<font color=blue>输出简要信息的区域</font>
    - 状态栏<font color=red>位于主窗口的最底部</font>
    - 状态栏中的消息类型
        - <font color=#d0d>实时消息</font>，如：当前程序状态
        - <font color=#00d>永久消息</font>，如：程序版本号，机构名称
        - <font color=red>进度消息</font>，如：进度条提示，百分比提示

- 在Qt中提供与<font color=blue>状态栏</font>相关的类组件
    ![](vx_images/029_1.png)
    > QStatusBar 本就是一个容器类型的类, 可以在这个类对应的对象中放置任意类型的QT组件

- 在Qt主窗口中创建状态栏
    ```c
    /* call member function */
    QStatusBar* sb = statusBar();
    /* create widget for Status Bar */
    QLabel* l = new QLabel("Label");
    QLineEdit* e = new QLineEdit();
    /* add widget to Status Bar */
    sb->addPermanentWidget(l);
    sb->addPermanentWidget(e);
    /* output message to Status Bar */
    sb->showMessage("D.T.Software");
    ```

- Qt状态栏的设计原则
    - <font color=red>左边的区域</font>用于输出<font color=red>实时消息</font>
    - <font color=blue>右边的区域</font>用于设置<font color=blue>永久消息</font>
    - <font color=red>addWidget</font> 在状态栏<font color=red>左半部分</font>添加组件
    - <font color=blue>addPermanentWidget</font> 在状态栏<font color=blue>右半部份</font>添加组件

# 2. 实验 - 状态栏的初体验

# 3. 实验 - 工具栏实战
代码框架
![](vx_images/029_e2.png)

# 4. 小结
- 状态栏是程序中<font color=blue>输出简要信息的区域</font>
- <font color=#d0d>QStatusBar</font> 是Qt中创建<font color=blue>状态栏</font>组件的类
- <font color=#d0d>QStatusBar</font> 中可以添加任意的QWidget
- <font color=#d0d>QStatusBar</font> 有自己<font color=red>内置的设计原则</font>
- <font color=#d0d>QStatusBar</font> 可以定制出<font color=#00d>各种形式</font>的状态栏