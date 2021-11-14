# 1. 存在的问题
- 目前的GUI开发方式 : <font color=red>绝对定位</font>
    - 直接在<font color=red>像素级</font>指定各个组件的<font color=red>位置</font>和<font color=red>大小</font>
        - `void QWidget::move(int x, int y)`
        - `void QWidget::resize(int w, int h)`
- 问题
    - 组件的位置和大小<font color=red>无法自适应父窗口的变化</font>

# 2. 实验 - 存在的问题
实验目录：[test](vx_attachments\022_Layout_manager_1\test)
代码：实验一

# 3. 布局管理器
- 解决方案 : <font color=red>布局管理器</font>
    - 提供相关的类<font color=red>对界面组件进行布局管理</font>
        - 能够<font color=red>自动排列</font>窗口中的界面组件
        - 窗口变化后<font color=red>自动更新界面组件的大小</font>

- 布局管理器介绍
    - `QLayout` 是 Qt 中<font color=red>布局管理器的抽象基类</font>
    - 通过继承 `QLayout` 实现了<font color=red>功能各异且互补</font>的布局管理器（非抽象基类）
    - Qt 中可以<font color=red>根据需要自定义</font>布局管理器
    - 布局管理器<font color=red>不是界面部件</font>, <font color=red>而是界面部件的定位策略</font>

![](vx_images/022_1.png)
> 有兴趣可实现自定义布局管理器

# 4. `QBoxLayout` 布局管理器
- `QBoxLayout` 布局管理器
    - 以<font color=red>水平</font>或者<font color=red>垂直</font>的方式管理界面组件

![](vx_images/022_2.png)

# 5. 实验 - QBoxLayout
实验目录：[test](vx_attachments\022_Layout_manager_1\test)
代码：实验二

- 替换绝对定位方式
    - `QSizePolicy` (默认大小策略是，layout中宽度跟着变化，高度不变)
    - 帮助文档 : 搜索 `QWidget` -> `QSizePolicy sizePolicy () const`

- 设置布局管理器间隔
    - `layout->setSpacing(30);`

# 6. 布局管理器的嵌套
- 布局管理器可以<font color=red>相互嵌套</font>, <font color=red>形成更加复杂的布局方式</font>
    - <font color=red>布局嵌套</font>几乎可以完成<font color=red>所有常用</font>的界面布局
    - <font color=red>自定义布局类</font>可以达到<font color=red>个性化界面布局</font>的效果
        > 自己编写一个布局管理器是个比较麻烦的事情，我们能用现成的就用现成的。
- QBoxLayout 嵌套实例
    ![](vx_images/022_3.png)

# 7. 实验 - 布局嵌套实例
实验目录：[test](vx_attachments\022_Layout_manager_1\test)
代码：实验三

# 8. 小结
- <font color=red>绝对定位</font>的布局方式<font color=red>无法自适应</font>窗口的变化
- Qt 提供了相关的类对<font color=red>界面组件进行布局管理</font>
- Qt 预定义了<font color=red>功能各异且互补</font>的布局管理器
- 布局管理器能够<font color=red>相互嵌套形成复杂的布局</font>

课后作业 :
改写计算器工程界面代码,使用layout