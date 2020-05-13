- 思考
还有哪些细节功能可以完善？
- 可以完善的一些关键点
-消息提示：当客户端收到消息时，能够提示用户
-系统消息：月艮务端向客户端主动发送消息
_用户名验证：用户名中不能包含非法字符
-快捷发送：按回车键发送输入框中的消息
- 消息提示
-思路：
•在客户端接收到消息时（MSGA),闪烁窗口
• void QWidget::activateWindow〇
On Windows, if you are calling this when the application is not currently the
active one then it will not make it the active window. It will change the color of
the taskbar entry to indicate that the window has changed in some way. This
is because Microsoft does not allow an application to interrupt what the user
is currently doing in another application.
网络聊天程序的完善
- 系统消息
-用户登录或退出时通知所有在线客户端
•登录
TextMessage msga(
"MSGA",
"[系统消息]\n === [ " + id + "]进入聊天室===\n "
)；
sendToAHOnlineUser(msga);
•退出
TextMessage tm(
"MSGA",
"[系统消息]\n === [ " + n->id + "]退出聊天室===\n
)；
sendToAHOnlineUser(tm);
- 用户名验证
-完善QLoginQialog使其能够对用户名进行合法性验证
•解决方案
- 快捷发送
一按回车键发送输入框中的消息
•解决方案：
1. 重写 MainWin 的 函数
2. 在inputEdit上安装事件过滤器
3. 当按下回车键时调用发送消息
编程实验 程序完善
专题预告
-  To be continued ...
除了 TCP接口，Qt平台也提供了 UDP接口吗?