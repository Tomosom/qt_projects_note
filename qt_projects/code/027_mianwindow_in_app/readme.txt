1. 主窗口的概念
    应用程序中的主窗口
    - 主窗口是与用户进行长时间交互的顶层窗口
    - 程序的绝大多数功能直接有主窗口提供
    - 主窗口通常是应用程序启动后显示的第一个窗口
    - 整个程序由一个主窗口和多个对话框组成
    
2. Qt中的主窗口 (参考 QMainWindow类继承.PNG)
    - Qt 开发平台中直接支持主窗口的概念
    - QMainWindow 是Qt中主窗口的基类
    - QMainWindow 继承于QWidget 是一种容器(非数据结构中的容器)类型的组件
    
3. QMainWindow 中封装的秘密 (参考 QMainWindow界面.PNG)

4. QMainWindow 中的组件布局 (参考 QMainWindow中的组件布局.PNG)

5. 主窗口中的菜单
    在 Qt 中提供与菜单相关的类组件 (参考 菜单相关类组件.PNG)
    
    在 Qt 主窗口中创建菜单:
    QMenuBar *mb = menuBar();   // member function
    QMenu *menu = new QMenu("File(&F)");
    QAction *action = new QAction("New", NULL);
    
    menu->addAction(action);
    
    mb->addMenu(menu);
    
6. 小技巧
    快捷键设置
        action->setShort(QKeySequence(KEY))
        - QKeySequence - Qt 中与快捷键相关的类
        - KEY - Qt 中代表键值的常量
