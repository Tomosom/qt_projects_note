Test : QString 类的简单测试
Calculator : 计算器程序完善,添加按钮到QLineEdit的显示

1. Qt 中的字符串类
    - 采用 Unicode 编码
        Qt 中的字符串类直接支持中日韩文等宽字符. STL中的String类不支持Unicode编码,只支持ASCII编码(WString类支持宽字符型的)
    - 使用 隐式共享技术 来节省内存和不必要的数据拷贝
        集合了深拷贝和浅拷贝的优点于一身的技术.
    - 跨平台使用,不必考虑字符串的平台兼容性
    
2. QString 相对于 STL 中的 String 的优点
    - QString 直接支持字符串和数字的相互转换
    - QString 直接支持字符串大小比较
    - QString 直接支持不同字符编码间的相互转换
    - QString 直接支持 std::string 和 std::wstring 的相互转换
    - QString 直接支持正则表达式的应用
    ...
    
.test
    创建项目 -> QT控件项目 -> Qt Gui应用 -> 下一步 -> 下一步 -> 基类:QWidget, 取消勾选创建界面