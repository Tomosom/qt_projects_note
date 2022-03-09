# 1. 查找对话框
- <font color=red>查找对话框</font>是应用程序中的<font color=red>常用部件</font>
    目标：开发一个可以<font color=red>在不同项目间复用</font>的查找对话框

- 需求
    - 查找对话框需求分析
        - <font color=red>可复用</font>软件部件
        - 查找文本框中的<font color=red>指定字符串</font>
        - <font color=red>能够指定查找方向</font>
        - 支持<font color=red>大小写敏感</font>查找 

        ![](vx_images/045_1.png)

    - 附加需求
        - <font color=red>点击关闭按钮后隐藏</font>

- 查找对话框的架构与设计
    ![](vx_images/045_2.png)

- 查找对话框的界面布局
    ![](vx_images/045_3.png)

# 2. 编程实验 查找对话框界面开发
实验目录：[NotePad](vx_attachments\045_Create_search_dialog\NotePad)
注：QT智能指针`QSharedPointer`的使用-c++深度解析

# 3. 小结
- 查找对话框可以作用一个<font color=red>可复用的软件部件</font>进行开发
- 查找对话框继承自 `QDialog` 类
- 查找对话框的界面通过布局管理器相互嵌套完成
- 查找对话框的设计与实现是<font color=red>GUI学习中的经典范例</font>
