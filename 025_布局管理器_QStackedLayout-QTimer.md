# 1. 最特别的布局管理器
## 1.1. 概念
- 栈式布局管理器（`QStackedLayout`)
    - 所有组件在<font color=red>垂直于屏幕</font>的方向上被管理
    - 每次<font color=red>只有一个组件</font>会显示在屏幕上
    - 只有<font color=red>最顶层的组件</font>会被最终显示

    ![](vx_images/025_1.png)

- 栈式布局管理器的特点
    - <font color=red>组件大小一致</font>且充满父组件的显示区
    - <font color=red>不能直接嵌套</font>其它布局管理器
    - 能够<font color=red>自甶切换</font>需要显示的组件
    - 每次能且仅能<font color=red>显示一个组件</font>

- `QStackedLayout`的用法概要

```c
/* 加入需要管理的组件（没有addLayout,所以不能嵌套其他布局管理器） */
int addWidget(QWidget*widget);
/* 返回当前栈式布局管理器最顶层的组件 */
QWidget *currentWidget();
/*
 * 用于切换当前应显示的组件
 * 每次向布局管理器中加入组件的时候，这些组件就有了一个编号（下标），
 * 第一个加入的组件下标为0，以此类推
 */
void setCurrentIndex(int index);
int currentlndex();
```
> 虽说不能直接进行布局管理器的嵌套，但可通过间接的方式来玩嵌套：将布局管理器附加到一个widget上

## 1.2. 实验 - 栈式布局初探
实验目录：[25-1](vx_attachments\025_Layout_manager_4\25-1)

# 2. 计时器
## 2.1. 概念
- 计时器的概念 - `QTimer`
    - 计时器是<font color=red>工程开发中</font>非常重要的角色
    - 计时器用于<font color=red>每隔一定的时间触发一个消息</font>
    - 计时器<font color=red>消息</font>最终会被转化为<font color=red>函数调用</font>
    - 宏观上
        - <font color=red>计时器在每个时间间隔会阔用指定的函数</font>

- Qt中的计时器
    - 计时器 (`QTimer`) 的使用方法
        1. 编写计时器消息处理函数
        2. 在程序中创建计时器对象
        3. 连接计时器消息和消息处理函数(信号与槽)
        4. 设置计时器时间间隔并启动计时

## 2.2. 实验 - 计时器的使用
实验目录：[25-1](vx_attachments\025_Layout_manager_4\25-1)

- 栈式布局管理器用途:
    - 用途一：安装软件时, 上一步/下一步 的界面
    - 用途二：嵌入式设备中 左划右划 的界面

# 3. 小结
- `QStackedLayout`以栈的方式管理界面组件
- `QStackedLayout`中的组件<font color=red>最多只有一个显示</font>
- `QStackedLayout`可以<font color=red>自甶切换</font>需要显示的组件
- `QTimer`是Qt中的计时器组件
- `QTimer`能够<font color=red>在指定的时间间隔</font>触发消息
