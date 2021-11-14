# 1. QBoxLayou比例系数
## 1.1. 使用方法
- 布局管理器中的<font color=red>比例系数</font>
    - <font color=red>默认情况下以等比例的方式</font>更新组件的大小
    - <font color=red>可以自定义</font>组件大小更新时的<font color=red>比例系数</font>

- `QBoxLayout`中的比例系数设置 (`QBoxLayout`的成员函数)
    - `void setStretch(int index, int stretch)`
        > index：格子下标；stretch：比例系数
    - `bool setStretchFactor(QWidget *widget, int stretch)`
        > 若`widget`组件并不存在`QBoxLayout`中时，返回false
    - `bool setStretchFactor(QLayout *layout, int stretch)`
        > 设置被嵌套的布局管理器的比例系数

## 1.2. 实验 - 比例系数
实验目录：[23-1](vx_attachments\023_Layout_manager_2\23-1)
> 组件的初始大小是<font color=red>独立于布局管理器</font>设置的（组件有默认的最小大小），因此<font color=red>不能保证组件的大小始终符合比例系数的设置</font>!

# 2. QGridLayout布局管理器
- `QGridLayout`布局管理器
    - 以<font color=red>网格（二维）</font>的方式管理界面组件

    ![](vx_images/023_1.png)

- `QGridLayout`中的<font color=red>比例系数</font>设置
    - `void setColumnStretch(int column, int stretch)`
    - `void setRowStretch(int row, int stretch)`

# 3. 实验 - QGridLayout
实验目录：[23-2](vx_attachments\023_Layout_manager_2\23-2)
> 子窗口占用多行或多列时规律 : 鼠标改动窗口大小时, 只会扩展占用行数或列数最小的窗口(widget)

# 4. QGridLayout布局管理器的嵌套
- `QGridLayout`支持<font color=red>嵌套其它布局管理器</font>成为其管理对象
![](vx_images/023_2.png)

# 5. 小结
- `QGridLayout` 以<font color=red>网格的方式</font>对组件进行管理
- `QGridLayout` 中的组件可以根据<font color=red>需要跨越多个网格</font>
- `QBoxLayout` 和 `QGridLayout` 支持<font color=red>比例系数</font>的概念
- <font color=red>比例系数</font>决定了组件大小的<font color=red>相对变化</font>

课后作业 :
上面图中QGridLayout布局管理器的嵌套实现