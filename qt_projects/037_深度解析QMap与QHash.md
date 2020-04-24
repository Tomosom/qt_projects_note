# QMap深度解析
- QMap是一个以升序键顺序存储键值对的数据结构
    - QMap 原型为 class QMap<K, T> 模板
    - QMap中的键值对根据 Key 进行了排序
    - QMap中的Key类型必须重载 operator <

- QMap使用示例一

```cpp
QMap<QString, int> map;

map* insert ("key 2", 2);
map* insert ("key 0", 0);
map* insert ("key 1", 1);

for(int i=0; i<3; i++)
{
    qDebug () << map.value ("key " + QString::number(i));
}

QList<QString> list = map.keys();
for(int i=0; i<list.count(); i++)
{
    qDebug() << list[i];
}
```

- QMap使用示例二

```cpp
QMap<QString, int> map;

map["key 2"] = 2;
map["key 0"] = 0;
map["key 1"] = 1;

for(int i=0; i<3; i++)
{
    qDebug() << map["key " + QString::number(i)];
}

QMapIterator<QString, int> it(map);

while( it.hasNext())
{
    it.next();
    qDebug() << it.key() << " : " << it.value();
}
```

- QMap的注意事项
    - 通过Key获取Value时：
        - 当Key存在：返回对应的Value
        - 当Key不存在：返回值类型所对应的"零"值
    - 插入键值对时：
        - 当Key存在：更新Value的值
        - 当Key不存在：插入新的键值对

# 编程实验 QMap使用体验

# QHash深度解析
- QHash是Qt中的哈希数据结构
    - QHash 原型为 class QHash<K, T> 模板
    - QHash中的键值对在内部无序排列
    - QHash中的Key类型必须重载operator ==
    - QHash中的Key对象必须重载全局哈希函数qHash()

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

# 编程实验 QHash 使用体验

# QMap和QHash对比分析
- QMap和QHash的接口相同，可直接替换使用
    - QHash的查找速度明显快于QMap
    - QHash占用的存储空间明显多于QMap
    - QHash以任意的方式存储元素
    - QMap以Key顺序存储元素
    - QHash 的键必须提供 operator==() 和 qHash(key)函数
    - QMap的键类型必须提供operator^()函数

# 编程实验 文本编辑器中的后缀映射

# 小结
- Qt中提供了用于存储键值对的类模板
- QHash和QMap遵循相同的使用接口
- QHash的查找速度快于QMap
- QMap需要的内存空间低于QHash
- QHash对于Key类型的要求高于QMap