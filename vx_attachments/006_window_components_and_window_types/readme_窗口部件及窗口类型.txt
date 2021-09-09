1. 窗口组件
    图形用户界面由不同的窗口和窗口组件构成
    <QtGui>头文件包含窗口组件,对应Qt中的GU模块
    组件的类型:
        容器类(父组件):用于包含其他的界面组件(及下面的功能类)
        功能类(子组件):用于实现特定的交互功能
    QT中比较重要的隐藏概念 : Qt中没有父组件的顶级组件叫做窗口(也就拥有了窗口的所有元素:标题栏,最大化,最小化,关闭按钮)
    
2. 窗口组件的继承关系
    QWidget类 继承自 QObject类 和 QPaintDevice类
    - QObject类是所有支持Qt对象模型的基类
    - QPaintDevice类是Qt中所有可绘组件的基类
    
        QObject                    QPaintDevice(继承此类有自绘能力)
           ^                            ^
           |                            |
           ------------------------------
                        |
                    QWidget
                        ^
                        |
        -------------------------------------
        |                    |                |
        QLable            QLineEdit        QPushButton
        
3. QWidget组件
    QWidget能够绘制自己和处理用户的输入
    QWidget是Qt中所有窗口类组件的父类(super class)
    QWidget是所有窗口组件的抽象
    QT中的每个窗口组件都是一个QWidget
    QWidget类对象常作为父组件或顶级组件使用
    
4. QLable组件
    QLable用于显示一个提示性的字符串
    QLable是功能性自荐,一般需要父组件作为容器
    QLable可以作为窗口存在,但没什么意义
    
        QWidget w;        // 生成QWidget对象,顶级组件
        QLable l(&w);    // 生成QLable对象,其父组件为QWidget
        /* 设置QLable组件的显示字符串 */
        l.setText("This is a Lable control.");

5. 窗口类型
    Qt 中可以根据需要定制窗口式样
    
    帮助文档中查看QWidget构造函数,第二各参数指明由QWidget生成的窗口的样式
    QWidget ( QWidget * parent = 0, Qt::WindowFlags f = 0 )
    
    帮助文档中查找: Qt::WindowType (窗口类型和窗口标志可用 或运算符 '|' 进行组合)
    - 窗口类型
        Qt::Dialog - 对话框类型
        Qt::Window - 主窗口类型
        Qt::SplashScreen - 启动画面类型
        ...
    - 窗口标志
        Qt::WindowStaysOnTopHint - 将该窗口作为顶级窗口,不会被其他窗口遮挡
        Qt::WindowContextHelpButtonHint - 最大化和最小化按钮转化为帮助按钮
        ...
    - 使用方法
        QWidget w;
        QWidget w(NULL, Qt::Dialog); // 最大化和最小化按钮没有了
        QWidget w(NULL, Qt::Window); // 有最大化和最小化按钮
        QWidget w(NULL, Qt::SplashScreen); // 所有按钮,标题栏均没有, 主要用来做应用程序的欢迎界面

. test
    创建项目 -> QT控件项目 -> Qt Gui应用 -> 下一步 -> 下一步 -> 基类:QWidget, 取消勾选创建界面