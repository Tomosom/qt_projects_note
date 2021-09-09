Qt 中的几何坐标以左上角为原点
    - 水平为x轴, 从左向右为正向
    - 垂直为y轴, 从上到下为正向

1. QWidget类中的坐标系统成员函数
    QWidget类提供了 3 组坐标相关的成员函数:(参考图coordinate.PNG)
    - x(), y(), width(), height()
    - geometry()
        x(), y(), width(), height()
    - frameGeometry()
        x(), y(), width(), height()
    提供 3 组坐标相关的成员函数原因:跨平台,适配不同操作系统
    
    注 : geometry()和frameGeometry()中的几何数据必须在show()调用后才有效!
    原因:写代码时,无法判断是哪种操作系统的窗口,QT在窗口显示出来之前无法得到真实有效的几何数据
    
2. QWidget类 窗口部件的大小设置
    QWidget类提供了成员函数:
    - 改变窗口部件的大小
        void resize(int w, int h) // 当宽度 w 小于操作系统规定窗口的最小值时,取最小值(比如win10 1080P的最小是152)
        void resize(const QSize &)
    - 改变窗口部件的位置
        void move(int x, int y)
        void move(const QPoint &)
        
3. QPushButton 组件
    QPushButton 是功能性组件,需要父组件作为容器,能够在父组件中进行定位
    
        QWidget W;          // 生成QWidget对象,顶级组件
        QPushButton b(&w);  // 生成QPushButton对象,其父组件为QWidget
        
        b.setText("Button");    //设置显示的字符串
        b.move(10, 10);         // 移动坐标
        b.resize(100, 25);      // 设置大小

4. QLineEdit 组件
    QLineEdit 用于接收用户输入
    QLineEdit 能够获取用户输入的字符串
    QLineEdit 是功能性组件, 需要父组件作为容器
    QLineEdit 能够在父组件中进行定位
        
        QWidget W;          // 生成QWidget对象,顶级组件
        QLineEdit le(&w);   // QLineEdit,其父组件为QWidget
        
        le.setAlignment(QT::AlignRight);    //设置显示的字符串向右边对其
        le.move(10, 10);    // 移动坐标
        le.resize(240, 30); // 设置大小

.test
    创建项目 -> QT控件项目 -> Qt Gui应用 -> 下一步 -> 下一步 -> 基类:QWidget, 取消勾选创建界面