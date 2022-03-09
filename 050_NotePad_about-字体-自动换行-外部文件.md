# 1. 关于对话框
- <font color=red>标准的桌面应用软件都有一个关于对话框</font>
- 关于对话框用于<font color=red>标识软件自身的信息</font>
    - 软件Logo, 项目名, 版本号
    - 开发者信息
    - 版权信息
    - 联系方式
    - 。。。

- 经典设计方案
![](vx_images/050_1.png)

# 2. 编程实验 关于对话框的创建
实验目录：[NotePad](vx_attachments\050_dialog_of_About\NotePad)

# 3. 开发目标
- [x] <font color=red>自定义文本编辑框中的字体和大小</font>
- [x] <font color=red>设置文本编辑框是否自动换行</font>
- [x] <font color=red>打开外部帮助文件</font>

# 4. 自定义字体及大小
- 实现思路
    - 通过`QFontDialog` 选择字体以及大小
    - 将 `QFont` 对象设置到<font color=red>文本编辑框</font>

# 5. 自动换行
- 实现思路
    - 获取当前文本编辑框的换行模式
    - <font color=red>将模式进行反转后并进行设置</font>
    - 更新对应 `QAction` 对象的状态

# 6. 打开外部文件
- `QDesktopServices` 提供了一系列桌面开发相关的服务接口
- 通过 `QDesktopServices` 中的成员函数打开帮助文件
    - `QDesktopServices::openUrl (QUrl("path"))`

# 7. 编程实验 项目持续开发
实验目录：[NotePad](vx_attachments\050_dialog_of_About\NotePad)

# 8. 小结
- <font color=red>关于对话框用于标识软件自身的信息</font>
- 使用 `QFontDialog` 设置文本编辑框的字体
- 设置文本编辑框的<font color=red>自动换行属性</font>
- 通过 `QDesktopServices` 使用桌面环境的系统服务
