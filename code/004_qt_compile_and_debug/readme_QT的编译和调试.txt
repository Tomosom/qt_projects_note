1. 通过命令行的方式编译QT源程序 (进入目录cmdline_compile)
    - 启动QT命令行,进入源程序所在目录(windows下可直接cmd进入代码目录)
    - 命令:
        1. qmake -project   // 根据目录中的源码生成工程文件
        2. qmake            // 根据工程文件生成Makefile文件
        3. make             // 根据Makefile进行编译
        
2. qt_creator的调试 (进入目录qt_creator_debug)
    将该代码放到 qt_creator 中编译:
    1.在目录命令行执行: qmake -project
    2.在 qt_creator 中打开生成的 .pro 文件

    QT调试的两种方式
    1.log调试： #include <QDebug>
    2.断点调试：在行号上右击，对断点进行 增加, 删除, 添加条件