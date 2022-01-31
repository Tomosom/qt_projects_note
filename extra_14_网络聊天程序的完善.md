# 1. 网络聊天程序的完善
- 思考
    还有哪些细节功能可以完善？

- 可以完善的一些关键点
    - 消息提示：当客户端收到消息时，能够提示用户
    - 系统消息：服务端向客户端主动发送消息
    - 用户名验证：用户名中不能包含非法字符
    - 快捷发送：按回车键发送输入框中的消息

- 消息提示
    - 思路：
        - 在客户端接收到消息时（MSGA), 闪烁窗口
        - void QWidget::activateWindow()

        ![](vx_images/.png)

- 系统消息
    - 用户登录或退出时通知所有在线客户端
        - 登录
        ```c
        TextMessage msga(
        "MSGA",
        "[系统消息]\n === [ " + id + " ] 进入聊天室 === \n "
        );
        sendToAllOnlineUser(msga);
        ```
        - 退出
        ```c
        TextMessage tm(
        "MSGA",
        "[系统消息]\n === [ " + n->id + " ] 退出聊天室 === \n"
        );
        sendToAllOnlineUser(tm);
        ```

- 用户名验证
    - 完善 QLoginQialog 使其能够对用户名进行合法性验证
        - 解决方案

        ![](vx_images/.png)

- 快捷发送
    - 按回车键发送输入框中的消息
        - 解决方案：
            1. 重写 MainWin 的函数
            2. 在 inputEdit 上安装事件过滤器
            3. 当按下回车键时调用 sendBtnClicked() 发送消息

# 2. 编程实验 程序完善
实验目录：[xxx](vx_attachments\xxx)

# 3. 专题预告
-  To be continued ...
    除了 TCP接口，Qt平台也提供了 UDP接口吗?
