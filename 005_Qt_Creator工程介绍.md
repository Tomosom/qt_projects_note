# 1. Qt Creator工程管理
- Qt Creator以<font color=red>工程项目的方式</font>对源码进行管理
- 一个Qt Creator工程包含<font color=red>不同类型</font>的文件
    - <mark>.pro项目描述文件</mark>
    - .pro.user用户配置描述文件
        > Qt Creator 自动生成的。如果我们的Qt Creator工程需要在不同的电脑之间进行拷贝的时候，这个文件是可以删除掉的。
    - .h头文件
    - .cpp源文件
    - .ui界面描述文件
        > Qt Creator提供可视化的方式让我们拖画出用户界面，对应的文件就是.ui界面描述文件。后续讲解到如何使用Qt designer设计GUI用户界面的时候会详细介绍。
    - 资源文件（图片，音频，等）

# 2. .pro项目描述文件
-  .pro项目描述文件的基本构成
    - `#` - 注释起始符
    - `QT` - 模块声明
        > 当前QT项目需要用到哪些模块
    - `TARGET` - 可执行文件名
    - `TEMPLATE` - 程序模板声明
        > 当前需要编译的是个可执行程序还是动态链接库还是静态链接库
    - `SOURCES` - 源码文件声明
    - `HEADERS` - 头文件声明
    - `FORMS` - 界面文件声明
        > 窗体，.ui界面描述文件
    - `RC_FILE` - 资源文件声明
- .pro项目描述文件中的高级变量
    - `INCLUDEPATH` - 头文件搜索路径
    - <mark>`CONFIG` - 设定项目的配置信息和编译选项</mark>
    - `LIBS` - 添加第三方库文件
    - `DEFINES` - 定义编译宏
- .pro文件的本质
    ![](vx_images/005_1.png)
    > .pro文件的本质为Qt中的Makefile文件！

# 3. CONFIG配置
- CONFIG用于设定项目的<font color=red>配置信息</font>和<font color=red>编译选项</font>
- CONFIG的常用选项
    - debug - 构建debug版本的可执行程序
    - release - 构建release版本的可执行程序
    - debug_and_release - 同时构建 debug 版和 release 版
    - warn_on - 尽可能多的输出警告信息
    - warn_off - 不输出警告信息

# 4. 实例分析 .pro项目文件分析 
.pro文件：[demo.pro](vx_attachments\005_qt_creator_engineering_file\demo.pro)

# 5. 项目文件
- <font color=red>一般来说</font>，项目文件中的描述都使用<font color=red>相对路径</font>
- 而相对路径是<font color=red>相对于项目文件本身</font>而言
- Qt Creator将<font color=red>项目文件</font>作为<font color=red>目标文件</font>
    > 注意：
    > 1. Qt Creator在打开项目文件的同时会生成<font color=red>.pro.user</font>文件
    > 2. .pro.user文件包含一些与Qt相关的本地配置信息
    > 3. 当需要在不同计算机之间移动项目源码时，建议<font color=red>删除</font>.pro.user文件

# 6. 工程中的概念
- 构建（<font color=red>build</font>）
    - 对项目中的<font color=red>所有文件进行编译</font>，最终<font color=red>生成可执行程序</font>

- Debug版
    - 可以<font color=red>进行程序调式</font>的构建版本
    - 可执行程序中<font color=red>包含调式信息，运行效率不高</font>

- Release 版
    - <font color=red>最终发布</font>的应用程序构建版本
    - <font color=red>无调式信息，运行效率高</font>

# 7. 编程实验 Qt Creator项目创建及分析
工程目录：[HelloWorld](vx_attachments\005_qt_creator_engineering_file\HelloWorld)

- 新建工程 HelloWorld
    - 打开 QtCreator -> 创建项目 -> QT控件项目 -> QT Gui应用
    - 选择基类为QMainWindow
    > 构建的项目生成的中间文件和可执行文件均会自动放到另一个目录

- 调试:
    单步跳过：执行到断点后，执行下一条语句
    单步进入：执行到断点后，若当前行有函数调用的话，就进入函数的内部

# 8. 小结
- Qt Creator以<font color=red>工程项目的方式</font>对源码进行管理
- 一个Qt Creator工程包含<font color=red>不同类型</font>的文件
- .pro文件用于<font color=red>配置</font>和<font color=red>组织</font>整个项目的相关信息
- .pro文件是Qt中<font color=red>与平台无关的Makefile文件</font>
- Qt Creator提供了<font color=red>开发所必备</font>的<font color=red>快捷高效</font>的功能
