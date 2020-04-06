1. Visual Studio 2010安装 （借助windows上的原生窗口应用程序开发，了解GUI基本原理）
1.1 点击 安装包目录下setup
1.2 点击 安装Microsoft Visual Studio 2010
1.3 下一步
1.4 我已阅读 下一步
1.5 选择自定义安装，更改安装目录到D盘， 下一步
1.6 仅保留 Visual C++, 图形库， 点击 安装
1.7 点击 完成 点击 退出
1.8 检查安装是否成功
    打开Visual Studio 2010应用程序，选择Visual C++ 开发设置，点击启动 visual studio
    点击文件->新建->项目， 选择MFC应用程序，输入名称Test, 选择目录, 确定 完成
    编译运行，正确弹出窗口即成功

2. windows 配置QT 环境
2.1 Qt Creator 2.4.1
    双击 qt-creator-win-opensource-2.4.1 运行， next， i accept, next, next, next,
    选择路径 d:\Qt\qtcreator-2.4.1， finish
2.2 Qt SDK4.7.4
    双击 qt-win-opensource-4.7.4-mingw 云心， next, i accept, next, next,
    选择路径 d:\Qt\4.7.4（最好将Qt Creator 和 Qt SDK安装在同一个目录）
    next， next
    指定mingw路径 D:\Qt\qtcreator-2.4.1\mingw（在安装的过程中指定 QT Creator 安装目录下的 mingw 文件夹）
    点击 安装
    next，finish
2.3 设置环境变量
    注意： 根据具体安装路径设置环境变量中的路径
    1) 将 D:\QT\4.7.4\bin;D:\QT\qtcreator-2.4.1\bin;D:\QT\qtcreator-2.4.1\mingw\bin 添加到 Path 变量
    2) 添加变量 LD_LIBRARY_PATH 并将其值设为 D:\QT\4.7.4\lib;D:\QT\qtcreator-2.4.1\lib
2.4 设置关联

    1) 运行：QT Creator
    2) 点击：工具 --> 选项... --> 构建和运行
    3) 选择：“Qt 版本”标签 --> 手动设置 --> 添加... --> 选择 D:\qt\4.7.4\bin\qmake.exe （根据具体安装路径进行选择）
    4) 点击：确定

3. ubuntu10( 已配置好QT ) 配置QT环境
    QT Version
    qt-everywhere-opensource-src-4.7.4
    qt-creator-linux-x86-opensource-2.4.1
3.1 安装QT
    1) 解压 qt-everywhere-opensource-src-4.7.4.tar.gz 到用户目录
    2) 进入解压的目录, 配置环境: sudo ./configure -> 选择'o'(开源版本) -> 接受协议yes
    3) 编译源码: sudo make
    4) 安装: sudo make install
3.2 安装QT Creator
    运行: sudo ./qt-creator-linux-x86-opensource-2.4.1.bin
    进入界面 -> 下一步 -> i accept -> 选择安装路径(建议和QT sdk安装在同一个目录,在/usr/local/Trolltech目录新建文件夹QtCreator, 安装目录选择:/usr/local/Trolltech/QtCreator)
3.3 设置环境变量
    在文件~/.bashrc末尾添加下面三行
    export QTDIR=/usr/local/Trolltech
    export PATH=$QTDIR/QT-4.7.4/bin:$QTDIR/QtCreator/bin:$PATH
    export LD_LIBRARY_PATH=$QTDIR/Qt-4.7.4/lib:$QTDIR/QtCreator/lib:$LD_LIBRARY_PATH
3.4 设置关联
    1) 运行: QT Creator ( 1. 直接命令行运行qtcreator ; 2. 应用程序(Application)->编程(Programming)->QT Creator)
    2) 点击: 工具-->选项...-->构建和运行
    3) 选择: "Qt 版本"标签-->手动设置-->添加...-->选择"/usr/local/Trolltech/QT-4.7.4/bin/qmake"
    4) 点击: 确定
