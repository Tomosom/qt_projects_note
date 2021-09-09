# QMap深度解析
- <font color=#d0d>QMap</font> 是一个以<font color=red>升序键顺序</font>存储<font color=red>键值对</font>的数据结构
    - <font color=#d0d>QMap</font> 原型为 `class QMap<K, T>` 模板
    - <font color=#d0d>QMap</font> 中的键值对根据 Key 进行了排序 (升序)
    - <font color=#d0d>QMap</font> 中的 Key 类型<font color=red>必须</font>重载 `operator <`

- QMap使用示例一
    ```cp
    QMap<QString, int> map;

    map.insert ("key 2", 2);
    map.insert ("key 0", 0);
    map.insert ("key 1", 1);

    for(int i = 0; i < 3; i++)
    {
        qDebug() << map.value("key " + QString::number(i));
    }

    QList<QString> list = map.keys();
    for(int i = 0; i < list.count(); i++)
    {
        qDebug() << list[i]; /* 将会有序打印 */
    }
    ```

- QMap使用示例二
    ```cp
    QMap<QString, int> map;

    map["key 2"] = 2;
    map["key 0"] = 0;
    map["key 1"] = 1;

    for(int i = 0; i < 3; i++)
    {
        qDebug() << map["key " + QString::number(i)];
    }

    /* 通过迭代器的对象来遍历map对象中的每个键值对 */
    QMapIterator<QString, int> it(map); /* 迭代器对象可以理解为一个指针 */

    while( it.hasNext() )
    {
        it.next();
        qDebug() << it.key() << " : " << it.value();
    }
    ```

- QMap的<font color=#d0d>注意事项</font>
    - 通过Key获取Value时：
        - 当Key存在：<font color=blue>返回对应的 Value</font>
        - 当Key不存在：返回值类型所对应的 <font color=#d0d>"零"</font> 值
    - 插入键值对时：
        - 当Key存在：<font color=blue>更新 Value 的值</font>
        - 当Key不存在：<font color=#d0d>插入新的键值对</font>

# [<u>编程实验 QMap使用体验</u>](code/037_Anatomy_of_QMap_and_QHash)

# QHash深度解析
- <font color=#d0d>QHash</font> 是Qt中的哈希数据结构
    - <font color=#d0d>QHash</font> 原型为 `class QHash<K, T>` 模板
    - <font color=#d0d>QHash</font> 中的键值对在内部无序排列
    - <font color=#d0d>QHash</font> 中的 Key 类型<font color=red>必须</font>重载 `operator ==`
    - <font color=#d0d>QHash</font> 中的 Key 对象<font color=red>必须</font>重载全局哈希函数 `qHash()`

- QHash使用示例
    ```c
    QHash<QString, int> hash;

    hash["key 2"] = 2;
    hash["key 0"] = 0;
    hash["key 1"] = 1;

    QHash<QString, int>::const_iterator i;

    for(i=hash.constBegin(); i != hash.constEnd(); ++i)
    {
        qDebug() << i.key() << " : " << i.value();
    }
    ```

# [<u>编程实验 QHash 使用体验</u>](code/037_Anatomy_of_QMap_and_QHash)

# QMap和QHash对比分析
- QMap 和 QHash 的接口相同，可直接替换使用
    - <font color=blue>QHash</font> 的查找速度明显快于 QMap
        > 因为使用 QHash 时必须 key 对象所对应的类型必须实现一个全局的 qHash() 函数, 查找会根据哈希函数计算出来的值来进行, 调用了qHash() 这个函数后, 就可以直接定位到对应的值在哪里, 速度上是占了优势, 这个优势是用空间替换来的
    - <font color=blue>QHash</font> 占用的存储空间明显多于 QMap
        > QMap 是用二分查找定位到对应的值的, 因此查找时间上, QMap 比不过 QHash
    - <font color=red>QHash</font> 内部以任意的方式存储元素
    - <font color=red>QMap</font> 内部以 Key 顺序存储元素
    - <font color=blue>QHash</font> 的键必须提供 `operator==()` 和 `qHash(key)` 函数
    - <font color=blue>QMap</font> 的键类型必须提供 `operator<()` 函数

# [<u>编程实验 文本编辑器中的后缀映射</u>](code/037_Anatomy_of_QMap_and_QHash)
解决自动保存文件后缀问题

# 小结<font color=#d0d>
- Qt中提供了用于存储键值对的</font>类模板
- <font color=blue>QHash</font> 和 <font color=red>QMap</font> 遵循相同的使用接口
- <font color=blue>QHash</font> 的查找速度快于 <font color=red>QMap</font>
- <font color=red>QMap</font> 需要的内存空间低于 <font color=blue>QHash</font>
- <font color=blue>QHash</font> 对于 <font color=#d0d>Key</font> 类型的要求高于 <font color=red>QMap</font>