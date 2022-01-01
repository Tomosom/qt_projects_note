# 1. QMap深度解析
- `QMap` 是一个以<font color=red>升序键顺序</font>存储<font color=red>键值对</font>的数据结构
    - `QMap` 原型为 `class QMap<K, T>` 模板
    - `QMap` 中的键值对根据<font color=red>Key</font>进行了排序 (升序)
    - `QMap` 中的<font color=red>Key</font>类型<font color=red>必须</font>重载 `operator <`

    > 'T' for template?

- `QMap` 使用示例一
    ```cpp
    QMap<QString, int> map;

    /* 成员函数方式来操作 */
    map.insert("key 2", 2);
    map.insert("key 0", 0);
    map.insert("key 1", 1);

    for (int i = 0; i < 3; i++) {
        qDebug() << map.value("key " + QString::number(i));
    }

    QList<QString> list = map.keys();
    for (int i = 0; i < list.count(); i++) {
        qDebug() << list[i]; /* 将会有序打印 */
    }
    ```

- `QMap` 使用示例二
    ```cpp
    QMap<QString, int> map;

    /* 数组方式来操作 */
    map["key 2"] = 2;
    map["key 0"] = 0;
    map["key 1"] = 1;

    for (int i = 0; i < 3; i++) {
        qDebug() << map["key " + QString::number(i)];
    }

    /* 通过迭代器的对象来遍历map对象中的每个键值对 */
    /* 迭代器对象可以理解为一个指针，指向map对象第一个元素之前的为位置 */
    QMapIterator<QString, int> it(map);
    while (it.hasNext()) {
        it.next();
        qDebug() << it.key() << " : " << it.value();
    }
    ```

- `QMap` 的<font color=red>注意事项</font>
    - 通过Key获取Value时：
        - 当Key存在：<font color=red>返回对应的 Value</font>
        - 当Key不存在：返回值类型所对应的 <font color=red>"零"</font> 值
    - 插入键值对时：
        - 当Key存在：<font color=red>更新 Value 的值</font>
        - 当Key不存在：<font color=red>插入新的键值对</font>

# 2. 编程实验 QMap使用体验
实验目录：[37-1](vx_attachments\037_Anatomy_of_QMap_and_QHash\37-1)
新建控制台工程

# 3. QHash深度解析
- `QHash` 是Qt中的哈希数据结构
    - `QHash` 原型为 `class QHash<K, T>` 模板
    - `QHash` 中的键值对在内部无序排列
    - `QHash` 中的<font color=red>Key</font>类型<font color=red>必须</font>重载 `operator ==`
    - `QHash` 中的<font color=red>Key</font>对象<font color=red>必须</font>重载全局哈希函数 `qHash()`

- `QHash` 使用示例
    ```cpp
    QHash<QString, int> hash;

    hash["key 2"] = 2;
    hash["key 0"] = 0;
    hash["key 1"] = 1;

    QHash<QString, int>::const_iterator i;
    for (i = hash.constBegin(); i != hash.constEnd(); ++i) {
        qDebug() << i.key() << " : " << i.value();
    }
    ```

# 4. 编程实验 QHash使用体验
实验目录：[37-2](vx_attachments\037_Anatomy_of_QMap_and_QHash\37-2)
新建控制台工程

- 哈希函数在哪里体现???
通用类型，若未定义哈希函数，有默认的哈希函数???

# 5. QMap和QHash对比分析
- `QMap` 和 `QHash` 的接口相同，可直接替换使用
    - `QHash` 的查找速度明显快于 `QMap`
        > - 因为使用 `QHash` 时, key 对象所对应的类型必须实现一个全局的 `qHash()` 函数, 查找会根据哈希函数计算出来的值来进行, 调用了`qHash()` 这个函数后, 就可以直接定位到对应的值在哪里, 速度上是占了优势, 这个优势是用空间替换来的
        > - `QMap` 是用二分查找定位(类似c库中的`qsort()`+`bsearch()`)到对应的值的, 因此查找时间上, `QMap` 比不过 `QHash`
    - `QHash` 占用的存储空间明显多于 `QMap`
        > `QHash` 是空间换时间
    - `QHash` 内部以任意的方式存储元素
    - `QMap` 内部以 Key 顺序存储元素
    - `QHash` 的键类型必须提供 `operator==()` 和 `qHash(key)` 函数
    - `QMap` 的键类型必须提供 `operator<()` 函数

# 6. 编程实验 文本编辑器中的后缀映射
实验目录：[NotePad](vx_attachments\037_Anatomy_of_QMap_and_QHash\NotePad)

- bug：当要保存新文件时，若用户输入的文件名没有加对应的后缀，则不会自动保存带此后缀的文件，当点击打开按钮时，在此过滤器下也无法看到上面保存的文件。
- 解决方法：将文件过滤描述字符串和对应的后缀字符串加入`QMap`中，用来索引后缀字符串。若用户保存时未输入特定后缀名，则自动将从`QMap`索引到的后缀字符串添加到文件名后面。
```cpp
    QMap<QString, QString> map;
    const char *filterArray[][2] = {
        {"Text Files (*.txt)", ".txt"},
        {"All Files (*)",      "*"   },
        {NULL,                 NULL  }
    };

    for (int i = 0; filterArray[i][0] != NULL; i++) {
        filters.append(filterArray[i][0]);
        map.insert(filterArray[i][0], filterArray[i][1]);
    }
```

# 7. 小结
- Qt中提供了用于存储键值对的<font color=red>类模板</font>
- `QHash` 和 `QMap` 遵循相同的使用接口
- `QHash` 的查找速度快于 `QMap`
- `QMap` 需要的内存空间低于 `QHash`
- `QHash` 对于 <font color=red>Key</font> 类型的要求高于 `QMap`
