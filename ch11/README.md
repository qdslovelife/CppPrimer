## exercise 11.1

1. `map`需要指定两个类型，一个是关键字类型，一个是值类型；`vector`只需要指定存储的元素类型。

2. `map`支持高效的关键字查找，`vector`一般使用标准库函数`find`查找，而`find`的查找速度不会很快。

3. `map`支持不同类型的对象作为下标，`vector`只能使用整数作为下标。

## exercise 11.2

`list`：不需要连续存储元素的情形，比如链表。

`vector`：用处比较广泛，没有特殊要求的话可以选择。

`deque`：如果只在头尾位置插入或删除元素，可以优先考虑`deque`。

`map`：用于存储关键字-值，比如字典之类的。

`set`：用于高效查找关键字，比如白名单之类的。

## [exercise 11.3](./11_3.cc)

## [exercise 11.4](./11_4.cc)

## exercise 11.5

`map`：存储关键字-值对。

`set`：只存储关键字。

根据编程需要，如果程序需要存储关键字-值对，那`map`是唯一的选择。

## exercise 11.6

`set`：不支持`list`支持的某些插入操作，不支持位置相关的操作。

`list`：不能高效查找，只能顺序遍历容器。

如果程序需要一个可以动态添加、删除元素的容器，可以选择`list`；如果程序存储的关键字是固定的，可以选择`set`。

## [exercise 11.7](./11_7.cc)

## [exercise 11.8](./11_8.cc)

`set`本身就支持保存不重复的单词，所以比`vector`更方便。

## exercise 11.9

``` c++
map<string, list<size_t>> words;
```

## exercise 11.10

可以定义，但是如果向容器中添加键-值对则无法通过编译。

因为迭代器不支持比较运算符，而编译器只有当编译插入操作时才会报告这个错误。

## exercise 11.11

``` c++
using Compare = bool (*)(const Sales_data &lhs, const Sales_data &rhs);
multiset<Sales_data, Compare> bookstore(compareIsbn);
```

## [exercise 11.12 & 11.13](./11_12.cc)

直接构造的方法最简单。

## exercise 11.14

``` c++
using Child = pair<string, string>;
using Children = vector<Child>;
map<string, Children>;
```

## exercise 11.15

`mapped_type`：`vector<int>`。

`key_type`：`int`。

`value_type`：`pair<const int, vector<int>>`。

## exercise 11.16

``` c++
map<string, string> item = {{"1", "2"}};
auto beg = item.begin();
beg->second = 3;
```

## exercise 11.17

第一个合法。

第二个非法。`multiset`没有`push_back`函数。

第三个合法。

第四个非法。

## exercise 11.18

`map<string, size_t>::const_iterator map_it;`

## exercise 11.19

`multiset<Sales_data, Compare>::iterator iter = bookstore.begin();`

## [exercise 11.20](./11_20.cc)

我觉得两个差不多，使用`insert`可能稍微好阅读一些。

## exercise 11.21

`++(word_count.insert({word, 0}).first->second);`

## exercise 11.22

参数类型：`pair<string, vector<int>>`

返回类型：`pair<pair<string, vector<int>>::iterator, bool>`

## exercise 11.23

`multimap<string, string>`

## exercise 11.24

如果关键字0存在，就将其关联的值设为1；如果关键字0不存在，就以0为关键字创建键-值对，其关联的值为1。

## exercise 11.25

将`v`的第一个元素的值设为1，如果`v`为空容器，则表达式非法。

## exercise 11.26

可以用`key_type`类型来对一个`map`进行下标操作，而下标运算符返回的类型为`mapped_type`。

## exercise 11.27

如果我想知道容器中有多少我准备查找的元素，就是用`count`，否则，使用`find`。

## exercise 11.28

`map<string, int>::iterator iter;`

## exercise 11.29

`lower_bound`和`upper_bound`都指向一个不影响排序的关键字插入位置。

`equal_range`返回一个`pair`, `pair`存储两个迭代器，都指向一个不影响排序的关键字插入位置。

## exercise 11.30

`pos.first`返回一个迭代器，指向关联容器中的一个键值对；然后使用`->second`访问键值对的值。

## [exercise 11.31](./11_31.cc)

## exercise 11.32

## [exercise 11.33](./11_33.cc)

## exercise 11.34

如果下标运算符没有找到指定的关键字，那么会创建一个新的键值对。

但是因为形参是一个`const`的引用，不能插入键值对，所以如果容器不存在指定的关键字，那么下标运算符会报错。

## exercise 11.35

插入一个已存在的键值对对容器没有任何影响，如果使用下标运算符，则已有的键值对的值就会被修改。

## exercise 11.36

我的代码会抛出`runtime_error`异常。

## exercise 11.37

因为无序容器不需要维护有序性，所以插入操作更快。

## [exercise 11.38](./11_38.cc)