# 1. 颜色对话框
- Qt 中提供了<font color=red>预定义的</font>颜色对话框`QColorDialog`类
- `QColorDialog`类用于提供<font color=red>指定颜色的对话框部件</font>
![](vx_images/020_1.png)
> 遗留问题：颜色对话框的这个自定义颜色是保存在哪里的，如何保证的下次打开的时候自定义颜色仍然存在？

- 颜色对话框的使用方式
    ```cpp
    /* 构造颜色对话框对象 */
    QColorDialog dlg(this);
    /* 设置颜色对话框的相关属性 */
    dlg.setWindowTitle("Color Editor");
    dlg.setCurrentColor(Qt::red); /* 初始颜色 */
    if (dlg.exec() == QColorDialog::Accepted) { /* 模态显示 */
        qDebug() << dlg.selectedColor();
    }
    ```

- QColor
    - Qt中的`QColor`类用来在程序中表示颜色的概念
    - `QColor`类同时支持<font color=red>多种颜色表示方式</font>
        - `RGB` : 以<font color=red>红, 绿, 蓝</font>为基准的<font color=red>三色模型</font>
        - `HSV` : 以<font color=red>色调, 饱和度, 明度</font>为基准的<font color=red>六角椎体模型</font>
        - `CMYK` : 以<font color=red>天蓝, 品红, 黄色, 黑</font>为基准的<font color=red>全彩印刷色彩模型</font>
    > `QColor`的应用领域：图像识别。
    > `QDebug()`的默认打印方式`QColor(ARGB 1, 0, 0, 1)`

- QColorDialog 中的实用函数
    - `QColorDialog::getColor`

# 2. 输入对话框
- Qt中提供了<font color=red>预定义的</font>输入对话框`QInputDialog`类
- `QInputDialog`类用于<font color=red>需要临时进行数据输入的场合</font>
![](vx_images/020_2.png)

- 输入对话框的实用方式
    ```cpp
    /* 构造输入对话框对象 */
    QInputDialog dlg(this);
    /* 设置输入对话框的相关属性 */
    dlg.setWindowTitle("Input Test");
    dlg.setLabelText("Please input an integer:");
    // dlg.setInputMode(QInputDialog::TextInput); /* 数入文本 */
    dlg.setInputMode(QInputDialog::IntInput);     /* 输入整数 */
    if (dlg.exec() == QInputDialog::Accepted) {
        // qDebug() << dlg.textValue();
        qDebug() << dlg.intValue();
    }
    ```
- 输入对话框的<font color=red>输入模式</font>
    - `QInputDialog::TextInput` - 输入文本字符串
    - `QInputDialog::IntInput` - 输入整型数
    - `QInputDialog::DoubleInput` - 输入浮点数

- `QInputDialog` 中的实用函数
    - `QInputDialog::getDouble`
    - `QInputDialog::getInt`
    - `QInputDialog::getItem` - 下拉选项
    - `QInputDialog::getText`

# 3. 小结
- `QColorDialog` 类用于<font color=red>提供指定颜色的对话框部件</font>
- `QColor` 类用来在程序中表示<font color=red>颜色</font>的概念
- `QInputDialog` 类用于<font color=red>需要临时进行数据输入的场合</font>
