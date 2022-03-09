# 1. 替换对话框
- 需求
    - 替换对话框需求分析
        - <font color=red>可复用</font>软件部件
        - 查找文本框中的<font color=red>指定字符串</font>
        - 替换<font color=red>单个</font>指定字符串
        - 替换<font color=red>所有</font>指定字符串
    - 附加需求
        - <font color=red>点击关闭按钮后隐藏</font>

    ![](vx_images/048_1.png)

- 替换对话框的设计与实现
![](vx_images/048_2.png)

- 替换对话框的界面布局
![](vx_images/048_3.png)

# 2. 编程实验 替换对话框的创建
实验目录：[NotePad](vx_attachments\048_Design_and_implementation_of_replacement_dialog\NotePad)

- 替换算法流程图
![](vx_images/048_4.png)

- `Mainwindows` 与 `ReplaceDialog` 之间的关系图
![](vx_images/048_5.png)

# 3. 编程实验 替换功能的实现
实验目录：[NotePad](vx_attachments\048_Design_and_implementation_of_replacement_dialog\NotePad)

# 4. 小结
- 替换对话框的功能<font color=red>涵盖了</font>查找对话框的功能
- 替换对话框可以<font color=red>继承自查找对话框</font>
- 替换功能的实现是<font color=red>基于查找算法完成的</font>
- 替换对话框是<font color=red>一个可复用的软件部件</font>