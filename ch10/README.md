## [exercise 10.1](./10_1.cc)

## [exercise 10.2](./10_2.cc)

## exercise 10.3

``` c++
vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;
```

## exercise 10.4

表达式是合法的，但是最终结果会舍弃小数，损失精度。

## exercise 10.5

调用非法。因为`const char*`并没有定义比较运算符。

## exercise 10.6

``` c++
vector<int> vec = {1,2,3,4,5,6,7};
fill_n(vec.begin(), vec.size(), 0);
```

## exercise 10.7

* (a) 有错误。容器`vec`是空的，不能作为输出容器。可以改为使用插入迭代器。

* (b) 没错误，但是没效果。可以改为`vec.resize(10)`

## exercise 10.8

算法只是将一个值赋给迭代器指向的对象，至于这个迭代器是如何实现赋值，算法并不关心。

所以改变容器大小的是插入迭代器，它改变了赋值运算符的定义。
## [exercise 10.9](./10_9.cc)

## exercise 10.10

目的是分离算法和成员函数的功能。

## [exercise 10.11](./10_11.cc)

## exercise 10.12

``` c++
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}
```

## [exercise 10.13](./10_13.cc)

## exercise 10.14

`auto f = [](int a, int b) { return a + b; };`

## exercise 10.15

``` c++
int sum(int a)
{
    auto f = [a](int b) { return a + b; };
}
```

## [exercise 10.16](./10_16.cc)

## exercise 10.17

`[](const Sales_data &lhs, const Sales_data &rhs){ return lhs.isbn() < rhs.isbn(); }`

## [exercise 10.18](./10_18.cc)

## [exercise 10.19](./10_19.cc)

## exercise 10.20

`count_if(words.begin(), words.end(), [](const string &s){ return s.size() > 6; })`

## [exercise 10.21](./10_21.cc)

## exercise 10.22

``` c++
bool bigger(const string &s, int sz)
{
    return s.size() >= sz;
}

auto bigger_ = bind(bigger, _1, 6);
```

## exercise 10.23

如果原调用对象需要`n`个参数，那么`bind`需要`n+1`个参数。

## exercise 10.24

``` c++
bool check_size(const string& s, string::size_type sz)
{
    return s.size() < sz;
}

vector<int>::const_iterator find_first_bigger(const vector<int>& v, const string& s)
{
    return find_if(v.cbegin(), v.cend(),
                   bind(check_size, s, std::placeholders::_1));
}
```

## [exercise 10.25](./10_25.cc)

## exercise 10.26

简单理解就是三种迭代器的插入位置不同。

## [exercise 10.27](./10_27.cc)

## [exercise 10.28](./10_28.cc)

## [exercise 10.29](./10_29.cc)

## [exercise 10.30](./10_30.cc)

## [exercise 10.31](./10_31.cc)

## exercise 10.32

## [exercise 10.33](./10_33.cc)

## [exercise 10.34](./10_34.cc)

## [exercise 10.35](./10_35.cc)

## exercise 10.36

``` c++
list<int> l = {1,2,3,4,5,6,7,8,9,0,6,7,8,5,0,7,8};
auto iter = find(l.crbegin(), l.crend(), 0);
```

## [exercise 10.37](./10_37.cc)

## exercise 10.38

## exercise 10.39

`list`的迭代器属于双向迭代器。

`vector`的迭代器属于随机访问迭代器。

## exercise 10.40

`copy`的前两个迭代器表示输入范围，属于输入迭代器；第三个迭代器表示输出范围，属于输出迭代器。

`reverse`的迭代器属于双向迭代器。

`unique`的迭代器属于前向迭代器。

## exercise 10.41

第一个是将输入范围中的旧值用新值代替。

第二个遍历输入范围，当某个元素使得谓词`pred`为真时，用新值代替。

第三个将输入范围中的元素拷贝到输出范围，同时用新值代替旧值。

第四个将输入范围中的元素拷贝到输出范围，同时当某个元素使得谓词`pred`为真时，用新值代替。

## exercise 10.42

``` c++
void elimDups(list<int> &words)
{
    words.sort();
    words.unique();
}
```