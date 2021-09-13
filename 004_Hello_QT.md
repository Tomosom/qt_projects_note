# 1. QT是什么?
- QT是一套跨平台的GUI开发库
- QT是一套C + +集成开发环境
- QT是一套开源的殿堂级架构技术教程

# 2. 进入QT的世界
- 第一个QT程序

```c
#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
int main(int argc, char* argv[])
(
    QApplication a(argc, argv);
    QMainWindow w;
    QPushButton b(&w);
    b.setText("Hello QT!");
    w.show();
    return a.exec();
)
```

# 3. QT开发环境
- 通过命令行的方式编译QT源程序
    - 启动QT命令行
    - 进入源程序所在目录
    - 命令：
        1. qmake-project // 根据目录中的源码生成工程文件
        2. qmake // 根据工程文件生成makefile文件
        3. make // 根据makefile进行编译

# 4. 编程实验 编译和运行第一个QT程序 4-1.cpp

# 5. QT Creator
- QT Creator 是一套可视化的集成开发环境
    - 使用 QT Creator 可以高效的进行QT开发
        - QT Creator 提供了强大的代码编辑功能
        - QT Creator 提供了强大的调试功能

# 6. 调式的基本方法
- Log调式法
    - 在代码中加入一定的打印语句
    - 打印程序状态和关键变量的值
- 断点调式法
    - 在开发环境中的对应代码行加上断点
    - 当程序运行到断点行时，程序暂停运行
    - 需要时课加上条件断点，当条件满足才暂停程序的运行

# 7. 编程实验 QT Creator 使用初体验 4-l.cpp

# 8. 小结
- QT是一套跨平台的C++界面开发库
- 可以通过命令行的方式开发QT应用程序
- 也可以通过QT Creator进行QT开发
- QT Creator同时支持Log调式法和断点调试法
