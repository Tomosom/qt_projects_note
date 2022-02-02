
# 1. 开发目标一
- <font color=red>指定目标行号并执行跳转动作</font>

# 2. 行间跳转
- 用户需求
    - 提供<font color=red>输入对话框</font>
    - 用户可输入<font color=red>目标行号</font>
    - <font color=red>确定后光标跳转到指定行</font>

- 行间跳转算法设计
    1. 通过输入对话框获取目标行号
    2. <font color=red>查找换行符的位置</font>计算目标行第一个字符的下标
    3. 通过 `QTextCursor` 定位到目标行

# 3. 编程实验 文本编辑器行间跳转
实验目录：[NotePad](vx_attachments\049_Text_editor_project_continues_to_develop\NotePad)

# 4. 开发目标二
- <font color=red>设置工具栏和状态栏的可见性</font>

- 实现思路
- 通过 `setVisible()` 设置可见性
- 更新界面上 `QAction` 对象的状态
    - 菜单中的 `QAction` 对象是否勾选
    - 工具栏中的 `QAction` 对象是否按下

# 5. 编程实验 可见性设置
实验目录：[NotePad](vx_attachments\049_Text_editor_project_continues_to_develop\NotePad)

# 6. 小结
- 通过输入对话框获取目标行并<font color=red>实现行间跳转</font>
- 根据用户操作控制<font color=red>状态栏</font>和<font color=red>工具栏</font>的可见性
- 菜单和工具栏中的 `QAction` 对象反映可见性状态
