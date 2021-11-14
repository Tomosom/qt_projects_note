# 1. 题目
- 思考
    如何设i十下面的图形用户界面？
    ![](vx_images/024_1.png)

- 解决方案
    - 方案1：`绝对定位`组件的坐标和大小
    - 方案2：嵌套 `QBoxLayout`
    - 方案3：创建 3x2 的 `QGridLayout`

    ![](vx_images/024_2.png)

# 2. 实验 - `QGridLayout` 的实现示例(复习内容)
实验目录：[24-1](vx_attachments\024_Layout_manager_3\24-1)

# 3. `QFormLayout`
- `QFormLayout`布局管理器
    - 以<font color=red>表单 (Form) </font>的方式管理界面组件
    - <font color=red>表单布局</font>中的<font color=red>标签</font>和<font color=red>组件</font>是<font color=red>相互对应</font>的关系

    ![](vx_images/024_3.png)

- `QFormLayout`的用法概要(重载的多个 函数)
```cpp
void addRow(QWidget *label, QWidget *field)
void addRow(QWidget *label, QLayout *field)
void addRow(const QString &labelText, QWidget *field)
void addRow(const QString &labelText, QLayout *field)
```
> 表单布局<font color=red>支持嵌套</font>，其它布局管理器<font color=red>可以作为子布局被其管理</font>。

- `QFormLayout`的样式函数(查看帮助文档)
```c
/* 行的换行方式 */
void setRowWrapPolicy(RowWrapPolicy policy)
/* 设置标签对齐方式 */
void setLabelAlignment(Qt::Alignment alignment)
```

# 4. 实验 - `QFormLayout` 的实现示例
实验目录：[24-2](vx_attachments\024_Layout_manager_3\24-2)

- 布局管理器的嵌套
    ![](vx_images/024_4.png)

# 5. 小结
- `QFormLayout`以<font color=red>表单</font>的方式管理界面组件
- `QFormLayout`的<font color=red>样式</font>设置<font color=red>简洁</font>明了
- `QFormLayout`支持布局管理器的<font color=red>相互嵌套</font>
- `QFormLayout`是嵌入式产品中<font color=red>最常用的布局方式</font>

作业: `QFormLayout`布局管理器的嵌套