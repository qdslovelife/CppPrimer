## exercise 3.1

## [exercise 3.2](./3_2.cc)

## exercise 3.3

输入运算符遇到空白字符就停止输入。

getline遇到换行符就停止输入。

## [exercise 3.4_1](./3_4_1.cc)

## [exercise 3_4_2](./3_4_2.cc)

## [exercise 3_5_1](./3_5_1.cc)

## [exercise 3_5_2](./3_5_2.cc)

## exercise 3.6

``` c++
for(auto &ch : str)
{
    ch = 'X';
}
```

## exercise 3.7

原来的字符串不会有任何改变，改变的只是拷贝的副本。

## exercise 3.8

`while`
``` c++
int i = 0;
while(i < str.size())
{
    str[i] = 'X';
    ++i;
}
```

`for`
``` c++
for(int i = 0; i < str.size(); ++i)
{
    str[i] = 'X';
}
```

## exercise 3.9

作用：输出字符串`s`的第一个字符。

非法，因为`s`是空串，不能使用下标去访问。

## [exercise 3.10](./3_10.cc)

## exercise 3.11

合法。`c`的类型为`const char &`。

## exercise 3.12

* (a) 合法。`vec`为空。

* (b) 非法。`int`与`string`不能进行类型转换。

* (c) 合法。`svec`有10个元素，每个元素的值均为`null`。

## exercise 3.13

* (a) 0个。

* (b) 10个，均为0。

* (c) 10个，均为42。

* (d) 1个，为10。

* (e) 2个，10和42。

* (f) 10个，均为空串。

* (g) 10个，均为'hi'。

## [exercise 3.14](./3_14.cc)

## [exercise 3.15](./3_15.cc)

## exercise 3.16

## [exercise 3.17](./3_17.cc)

## exercise 3.18

非法。不能对空容器进行下标操作。

可以改为`ivec.push_back(42);`

## exercise 3.19

1. `vector<int> vec(10, 42);`

2. `vector<int> vec{42,42,42,42,42,42,42,42,42,42};`

3. 用`for`循环向容器添加元素。

第一种方法好，简单方便又实用。

## [exercise 3.20.1](./3_20_1.cc)

## [exercise 3.20.2](./3_20_2.cc)

## exercise 3.21

## exercise 3.22

``` c++
for(auto it = text.begin(); it != text.end() && !it->empty(); ++it)
{
    for(auto &ch : *it)
    {
        ch = toupper(ch);
    }
    cout << *it << endl;
}
```

## [exercise 3.23](./3_23.cc)

## [exercise 3.24.1](./3_24_1.cc)

## [exercise 3.24.2](./3_24_2.cc)

## exercise 3.25

``` c++
vector<unsigned> scores(11, 0);
vector<int>::iterator it;
unsigned grade;
while(cin >> grade)
{
    it = vec.begin()
    if(grade <= 100)
    {
        it += grade / 10;
        ++(*it);
    }
}
```

## exercise 3.26

可以把迭代器看作是封装后的指针。指针显然是不能直接相加（可以相减）的，所以迭代器自然也不可以直接相加。

## exercise 3.27

* (a) 非法。数组的大小必须是常量表达式。

* (b) 合法。

* (c) 非法。数组的大小必须是常量表达式。

* (d) 非法。字符串字面值有一个`\0`结尾，所以长度应为12。

## exercise 3.28

字符串是自定义类类型，执行默认初始化的结果为空串。

`ia`在全局作用域中，所以初始化为0；`ia2`是局部变量，默认初始化的结果是未定义的。

## exercise 3.29

* 不能动态地增删元素。

* 必须在定义时提供数组大小。

## exercise 3.30

数组的索引从0开始，所以`ia[10]`是非法的。

## exercise 3.31

``` c++
int ia[10];
for(int i = 0; i < 10; ++i)
{
    ia[i] = i;
}
```

## exercise 3.32

数组必须逐元素拷贝，`vector`可以直接使用`=`进行拷贝。

## exercise 3.33

如果不初始化，那么数组中的值是未定义的，可能是任意值。

## exercise 3.34

使得`p1`指向与`p2`相同的数组元素。

当`p1`或者`p2`引用非法内存时，表达式是非法的。

## exercise 3.35

``` c++
int ia[10] = {1,2,3,4,5,6,7,8,9,10};
int *beg = begin(ia);
while(beg != end(ia))
{
    *beg = 0;
    ++beg;
}
```

## exercise 3.36

数组必须逐元素比较，而`vector`可以直接使用`==`或者`!=`进行比较。

## exercise 3.37

程序会不断执行下去，直到找到一个空字符为止。

如果不使用字符串字面值初始化字符数组，一定要记得手动添加一个空字符。

## exercise 3.38

指针值都是很大的十六进制值，直接相加会指向一个匪夷所思的地方，其值完全不可预测。

## exercise 3.39

C风格字符串使用`strcmp`进行比较，`string`可以使用`==`或者`!=`进行比较。

## [exercise 3.40](./3_40.cc)

## exercise 3.41

``` c++
int ia[10] = {1,2,3,4,5,6,7,8,9,10};
vector<int> vec(begin(ia), end(ia));
```

## exercise 3.42

``` c++
vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int int_arr[10];

for (int* i = begin(int_arr); i != end(int_arr); ++i)
{
    *i = ivec[i - begin(int_arr)];
}
```

## exercise 3.43

## exercise 3.44

## exercise 3.45