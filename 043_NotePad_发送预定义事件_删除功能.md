# 1. 在程序中发送事件

> 根据前面学习：事件是QT平台用于描述用户操作的对象。
> 事件对象的由来<font color=red>不只</font>是操作系统带来的，我们也可以在程序里边自主地发送事件对象。

- Qt中可以在程序中<font color=red>自主发送事件</font>
    - <font color=red>阻塞型</font>事件发送
        - 事件发送后需要等待事件处理完成
    - <font color=red>非阻塞型</font>事件发送
        - 事件发送后立即返回
        - 事件被发送到**事件队列**中等待处理

- `QApplication` 类提供了支持事件发送的静态成员函数
    - <font color=red>阻塞型</font>发送函数：
        - `bool sendEvent(QObject *receiver, QEvent *event);`
    - <font color=red>非阻塞型</font>发送函数：
        - `void postEvent(QObject *receiver, QEvent *event);`

- 注意事项
    - `sendEvent` 中事件对象的生命期甶 Qt 程序管理（因为它是阻塞型发送）
        - 同时支持<font color=red>栈事件对象</font>和<font color=red>堆事件对象</font>的发送（不管事件对象是在哪里创建的，都可以被这个`sendEvent`成员函数所发送）
    - `postEvent` 中事件对象的生命期由 Qt 平台管理
        - 只能发送<font color=red>堆事件对象</font>
        - <font color=red>事件被处理后由Qt平台销毀</font>

    > 若不遵守，可能程序崩溃。

- 使用`sendEvent`发送事件对象（<font color=red>阻塞型</font>）
    ![](vx_images/043_1.png)

    小贴士 ：
    消息发送过程可以理解为：在`sendEvent()`函数内部<font color=red>直接调用 Qt 对象的 event() 事件处理函数</font>。

- 使用`postEvent`发送事件对象（<font color=red>非阻塞型</font>）
    ![](vx_images/043_2.png)

    > dispatch()：分发。

# 2. 编程实验 在程序中发送事件
实验目录：[43-1](vx_attachments\043_Sending_custom_events_1\43-1)

新建项目->Qt 控件 项目->Qt Gui 应用

实验现象：

1. 双击空白处，打印：
```
event():  QMouseEvent(MouseButtonDblClick, 1, 1, 0)
```
2. 点击sendEvent，打印：
```
Before sendEvent()
event():  QMouseEvent(MouseButtonDblClick, 1, 0, 0)
After sendEvent()
```
3. 点击postEvent，打印：
```
Before postEvent()
After postEvent()
event():  QMouseEvent(MouseButtonDblClick, 1, 0, 0)
```

# 3. 文本编辑器中的事件发送
- 菜单栏中删除功能的实现
    1. 定义事件对象 `KeyPress`
    2. 定义事件对象 `KeyRelease`
    3. 发送事件 `KeyPress`
    4. 发送事件 `KeyRelease`
    ![](vx_images/043_3.png)
    > 总体思路: 对键盘的delete按键的封装

# 4. 编程实验 文本编辑器中的事件发送
实验目录：[NotePad](vx_attachments\043_Sending_custom_events_1\NotePad)

```c++
void MainWindow::onEditDelete()
{
    // Qt::NoModifier指的是我们单纯地按下的只是一个键，不包括ctrl,alt等其他功能键
    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_Delete, Qt::NoModifier);
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_Delete, Qt::NoModifier);
    QApplication::sendEvent(&mainEditor, &keyPress);
    QApplication::sendEvent(&mainEditor, &keyRelease);
}
```

菜单栏exit的实现
```c++
void MainWindow::onFileExit()
{
    close();
}
```

# 5. 小结
- Qt 程序中能够自主的发送系统事件
- `QApplication` 类提供了支持事件发送的成员函数
- `sendEvent()` 发送事件后需要等待事件处理完成
- `postEvent()` 发送事件后立即返回
