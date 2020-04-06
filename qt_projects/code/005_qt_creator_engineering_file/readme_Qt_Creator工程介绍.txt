1. QtCreator 工程管理
    QtCreator 以工程项目的方式对源码进行管理
    一个 QtCreator 工程包含不同类型的文件
        .pro 项目描述文件
        .pro.user 用户配置描述文件 (QtCreator 自动生成, 若QtCreator工程需要在不同的电脑之间进行拷贝时,这个文件其实是可以删除掉的)
        .h 头文件
        .cpp 源文件
        .ui 界面描述文件 (拖画出的用户界面对应的文件,后续讲解QtDesigner设计GUI用户界面的时候详细介绍)
        资源文件(图片, 音频, 等)
    
2. .pro 项目描述文件 ( 有点类似Makefile.param, .pro文件 -> qmake -> Makefile文件 )
    .pro 项目描述文件的基本构成
        - # - 注释起始符
        - QT - 模块声明(关键字, 该QT项目会用到哪些模块(类),除开发界面外,还可 数据库连接类,多线程类,网络连接类,等)
        - TARGET - 可执行文件名
        - TEMPLATE - 程序模板声明(生成可执行文件还是库文件)
        - SOURCES - 源码文件声明
        - HEADERS - 头文件声明
        - FORMS - 界面文件声明(窗体)
        - RC_FILE - 资源文件声明
    .pro 项目描述文件中的高级变量
        - INCLUDEPATH - 头文件搜索路径
        - CONFIG - 设定项目的配置信息和编译选项
        - LIBS - 添加第三方库文件
        - DEFINES -定义编译宏
        
3. CONFIG配置
    CONFIG 用于设定项目的配置信息和编译选项
    CONFIG 的常用选项
        - debug - 构建debug版本的可执行程序
        - release -    构建release版本的可执行程序
        - debug_and_release - 同时构建debug版和release版
        - warn_on - 尽可能多的输出警告信息
        - warn_off - 不输出警告信息
        
4. 注:
    一般来说,项目文件中的描述都使用相对路径,而相对路径是相对于项目文件本身而言,QtCreator将项目文件作为目标文件
    - QtCreator 在打开项目文件的同时会生成 .pro.user 文件
    - .pro.user文件包含一些与Qt相关的本地配置信息
    - 当需要在不同计算机之间移动项目源码时,建议删除 .pro.user 文件
    
5. 新建工程 HelloWorld
    打开 QtCreator -> 创建项目 -> QT控件项目 -> QT Gui应用
    (构建的项目生成的中间文件和可执行文件均会自动放到另一个目录)

    调试:
    单步跳过:执行到断点后,执行下一条语句
    单步进入:执行到断点后,若当前行有函数调用的话,就进入函数的内部