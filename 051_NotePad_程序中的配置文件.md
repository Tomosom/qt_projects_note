# 1. 程序中的配置文件
- 应用程序在运行后都有一个<font color=red>初始化</font>的状态
- <font color=red>—般而言：</font>
    - 程序的初始状态是<font color=red>最近一次运行退出前的状态</font>

- 问题
    如何<font color=red>保存</font>和<font color=red>恢复</font>程序状态？

- 解决思路
    - 程序退出前<font color=red>保存状态参数</font>到文件（<font color=red>数据库</font>)
    - 程序再次启动时<font color=red>读出状态参数并恢复</font>

- 状态参数的存储方式
    - <font color=red>文本文件格式</font>（XML, JSon, 等）
    - <font color=red>轻量级数据库</font>（Access, SQLite, 等）
    - <font color=red>私有二进制文件格式</font>

- Qt中的解决方案
    - 通过<font color=red>二进制数据流</font>将状态参数直接存储于文件中（`QDataStream`）
    - 优势：
        - <font color=red>参数的存储和读取简单高效</font>，易于编码实现
        - 最终文件为二进制格式，<font color=red>不易被恶意修改</font>

- 设计与实现
    ![](vx_images/051_1.png)

# 2. 编程实验 文本编辑器的状态配置
实验目录：[NotePad](vx_attachments\051_Configuration_files_in_the_program\NotePad)

注：`QDataStream`需指定版本号，方便指定文件的移植
```cpp
QDataStream in(&file);
in.setVersion(QDataStream::Qt_4_7);

QDataStream out(&file);
out.setVersion(QDataStream::Qt_4_7);
```

提取函数：`dynamic_cast`方式查找工具栏的函数：`QToolBar* toolBar();`

> `restore()`成员函数暂未用到。

# 3. 小结
- 应用程序中在退出时保存程序状态（<font color=red>用户配置</font>）
- 应用程序启动时恢复最近一次的程序状态
- 可以通过二进制数据流将状态参数<font color=red>直接存储于文件中</font>
- <font color=red>二进制数据流</font>的方式非常的安全，简单，高效
