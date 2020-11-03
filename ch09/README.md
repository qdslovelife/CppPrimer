## exercise 9.1

* (a) `list`。按字典序插入容器中会要求在容器的中间位置插入元素，因此`list`是最佳选择。

* (b) `deque`。在容器末尾插入、头部删除，`deque`是最佳选择。

* (c) `vector`。程序可以将正数插入的`vector`的末尾，然后调用`sort`函数对`vector`进行排序。


## exercise 9.2

`list<deque<int>> l;`

## exercise 9.3

假定构成迭代器范围的两个迭代器分别为`begin`和`end`，则限制如下：

* `begin`和`end`必须指向相同的容器。

* `end`不能指向`begin`之前的位置。

## exercise 9.4

``` c++
bool find(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
    while(begin != end)
    {
        if(*begin == val)   return True;
        ++begin;
    }
    return False;
}
```

## exercise 9.5

``` c++
vector<int>::iterator find(vector<int>::iterator begin, vector<int>::iterator end, int val)
{
    while(begin != end)
    {
        if(*begin == val)   return begin;
        ++begin;
    }
    return end;
}
```

## exercise 9.6

`list`的迭代器不支持小于运算符。

## exercise 9.7

`vector<int>::iterator`

## exercise 9.8

`list<string>::const_reference`

`list<string>::reference`

## exercise 9.9

`begin`函数返回的迭代器依赖于对象，如果是常量对象，返回常量迭代器，否则是普通迭代器。

`cbegin`函数一定返回常量迭代器。

## exercise 9.10

`it1`：`vector<int>::iterator`

`it2`：`vector<int>::const_iterator`

`it3`：`vector<int>::const_iterator`

`it4`：`vector<int>::const_iterator`

## exercise 9.11

* `vector<int> vec;`

* `vector<int> vec(10)`

* `vector<int> vec(10, 5)`

* `vector<int> vec{10, 5}`

* `vector<int> vec(old_vec)`

* `vector<int> vec(begin, end)`

## exercise 9.12

拷贝容器的构造函数不仅要求元素类型相同，还要求容器类型必须相同。

拷贝迭代器范围的构造函数只要求元素类型匹配（可以转换）。

## exercise 9.13

``` c++
list<int> l1 = {1,2,3,4};
vector<int> v1 = {1,2,3,4}

vector<double> v2(l1.cbegin(), l2.cbegin());
vector<double> v3(v1.cbegin(), v1.cend());
```

## exercise 9.14

``` c++
list<char*> l = {"hello", "world"};
vector<string> vec;
vec.assign(l.cbegin(), l.cend());
```

## exercise 9.15

``` c++
vector<int> vec1 = {1,2,3,5,6};
vector<int> vec2 = {1,4,3,4,6};
cout << vec1 < vec2 << endl;
```

## exercise 9.16

``` c++
list<int> l1 = {1,2,3,4,5};
vector<int> v1 = {1,2,3,4,5};

vector<int> v2(l1.cbegin(), l1.cend());
cout << v1 < v2 << endl;
```

## exercise 9.17

如果这两个容器的元素类型不支持小于运算符，那么表达式是非法的。

## [exercise 9.18](./9_18.cc)

## [exercise 9.19](./9_19.cc)

## exercise 9.20

``` c++
list<int> l = {1,2,3,4,5,6,7,8,9,10};
deque<int> d1;
deque<int> d2;
auto iter = l.cbegin();
while(iter != l.cend())
{
    if(*iter % 2 == 0)  d1.push_back(*iter);
    else    d2.push_back(*iter);
    ++iter;
}
```

## exercise 9.21

效果是一样的，但是`vector`会慢很多。

## exercise 9.22

`while`循环没有改变`iter`的值，所以会无限循环。 

## exercise 9.23

四个变量的值是相同的。

## [exercise 9.24](./9_24.cc)

## exercise 9.25

只要`elem1`和`elem2`表示一个有效的迭代器范围，那么当`elem1 = elem2`时，不会有任何元素被删除。

## exercise 9.26

``` c++
vector<int> vec = {0,1,1,2,3,5,8,13,21,55,89};
list<int> l = {0,1,1,2,3,5,8,13,21,55,89};
auto iter1 = vec.begin();
auto iter2 = l.begin();
while(iter1 != vec.end())
{
    if(*iter1 % 2)  ++iter1;
    else    iter1 = vec.erase(iter1);
}
while(iter2 != l.end())
{
    if(*iter2 % 2)  iter2 = l.erase(iter2);
    else    ++iter2;
}
```

## exercise 9.27

``` c++
forward_list<int> flst = {1,2,3,4,5,6,7,8,9,10};
auto prev = flst.before_begin();
auto curr = flst.begin();
while(curr != flst.end())
{
    if(*curr % 2)   curr = flst.erase_after(prev);
    else    
    {
        prev = curr;
        ++curr;
    }
}
```

## exercise 9.28

``` c++
void func(forward_list<string>& flst, const string &s1, const string &s2)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while(curr != flst.end())
    {
        if(*curr == s1)
        {
            flst.insert_after(prev, s2);
            return;
        }
        prev = curr;
        ++curr;
    }
    flst.insert_after(prev, s2);
}
```

## exercise 9.29

`vec.resize(100)`：`vec`的大小变为100，且新增的元素全部使用值初始化。

`vec.resize(10)`：`vec`的大小变为10，多余的元素被删除。

## exercise 9.30

如果元素类型为类类型，且没有默认构造函数，那么`resize`增大容器的操作会失败。

## exercise 9.31

这两个容器的迭代器都不支持算术运算。

## exercise 9.32

非法。当我们调用函数时，函数调用结果不应该依赖于计算实参的顺序。

## exercise 9.33

程序会漏处理一些元素。

## exercise 9.34

题目的代码有问题，`while`循环没有加花括号，所以会导致无限循环。

然而即使加上花括号，代码也会无限循环。

## exercise 9.35

`capacity`表示容器最多能存储多少元素。`size`表示容器现在存储了多少元素。

## exercise 9.36

不可能。

## exercise 9.37

`list`的元素不是连续存储，理论上可以不断地添加元素。

`array`的大小是固定的，同时也是类型的一部分，不需要`capacity`函数。

## exercise 9.38

## exercise 9.39

从输入中读取字符串存储到容器`svec`中，然后将`svec`的大小扩展为输入字符串数量的1.5倍。

## exercise 9.40

## exercise 9.41

``` c++
vector<char> vec = {'a','b'};
string s(vec.cbegin(), vec.cend());
```

## exercise 9.42

创建字符串之后将字符串的预留空间设置为大于100，这样可以避免在插入字符的过程中频繁地增大容器甚至将容器拷贝到新的内存空间中。