# 1. 018_登录对话框实例分析
- <font color=red>登陆对话框</font>是应用程序中的<font color=red>常用部件</font>
    思考:
    如何开发一个可以在不同项目间<font color=red>复用</font>的登陆对话框?

- 登陆对话框的核心需求
    - <font color = red>可复用</font>软件部分
    - 获取<font color = red>用户名</font>和<font color = red>密码</font>
    - 附加需求 : <font color = green>随机验证码</font>

    ![](vx_images/018_1.png)

- 登陆对话框的设计与架构
    ![](vx_images/018_2.png)

# 2. 实例分析
工程目录：[login](vx_attachments\018_Login_dialog_instance_analysis\login)
`setFixedSize(285, 170); /* 对话框的大小不可变 */`
`PwdEdit.setEchoMode(QLineEdit::Password); /* 设置编辑框密码显示为*号 */`

- 设计要点 : 如何获取用户输入的用户名和密码?
    扩展为通用问题 : <font color = red>如何在两个不同的对话框间传递数据?</font>
    解决方案:(开接口)
    ![](vx_images/018_3.png)
    通过附加的<font color = red>成员变量</font>和<font color = red>成员函数</font>,
    完成不同对话框将的<font color = red>数据传递</font>!

- 尚待完善的地方:
    1. 检查<font color = red>用户名</font>和<font color = red>密码</font>是否为空
        - 当用户名或密码<font color = red>为空时提示错误</font>
    2. 随机验证码
        - 当验证码输入<font color = red>错误时进行提示</font>
        - <font color = red>验证码随机刷新</font>

# 3. 小结
- 登陆对话框作为<font color = red>可复用的软件部分</font>进行开发
- 对话框之间通过<font color=red>成员变量</font>和<font color=red>成员函数</font>传递数据
    - <font color=red>将用户数据保存在私有成员变量中</font>
    - <font color=red>通过公有成员函数进行数据传递</font>

