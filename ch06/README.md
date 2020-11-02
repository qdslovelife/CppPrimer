## exercise 6.1

形参：作用域和生命周期都在函数体内的局部变量，使用实参进行初始化。

实参：用于初始化形参。

## exercise 6.2

* (a) 返回类型和实际返回的对象不匹配。可以将函数的返回类型改为`string`。

* (b) 没有声明返回类型。如果确定不返回任何对象，可以将返回类型改为`void`。

* (c) 缺少一个左花括号。

* (d) 缺少花括号。

## exercise 6.3

``` c++
int fact(int val)
{
    int ret = 1;
    while(val > 1)
    {
        ret *= val--;
    }
    return ret;
}
```

## [exercise 6.4](./6_4.cc)

## exercise 6.5

``` c++
int abs(int val)
{
    return val < 0 ? -val : val;
}
```

## exercise 6.6

形参：作用域和生命周期都在函数体内，使用实参进行初始化。

局部变量：作用域和生命周期都在函数体内，使用给定的值进行初始化或进行默认初始化。

局部静态变量：作用域在函数体内，生命周期从定义开始，直到程序结束，使用给定的值进行初始化或进行默认初始化。

``` c++
void test(int parameter)
{
    int loval_variable = 0;
    static int local_static_variable = 0;
}
```

## exercise 6.7

``` c++
int test()
{
    static int count = 0;
    return count++;
}
```

## exercise 6.8 | [Header](./Chapter6.h)

## exercise 6.9 | [Source](./fact.cc), [Main](./factMain.cc)

## [exercise 6.10](./6_10.cc)

## exercise 6.11

``` c++
void reset(int &i)
{
    i = 0;
}
```

## exercise 6.12

``` c++
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
```

传引用方便点，因为不需要解引用，调用函数时也不需要取地址。

## exercise 6.13

第一个是传值调用，第二个是传引用调用。

## exercise 6.14

当形参类型为输入流或输出流时，应该使用引用。

当形参为迭代器，表示一个迭代器范围时，最好不要用引用。

## exercise 6.15

`s`：引用是因为`string`的拷贝浪费时间，加`const`是因为函数不应该修改形参。

`c`：`char`拷贝很快，所以直接拷贝；因为是拷贝，所以是不是`const`无所谓。

`occurs`：引用和不加`const`都是因为函数需要通过形参来修改实参。

## exercise 6.16

这个函数无法适用于`const string`，可以将形参声明改为`const string &s`。

## exercise 6.17

``` c++
bool has_upper(const string &s)
{
    for(auto &ch : s)
    {
        if(isupper(ch))
        {
            return True;
        }
    }
    return False;
}
```

``` c++
void set_lower(string &s)
{
    for(auto &ch : s)
    {
        tolower(ch);
    }
}
```

形参类型不相同。

第一个函数声明为`const string &s`，第二个函数声明为`string &s`。因为第二个函数需要修改形参，第一个不需要。

## exercise 6.18

`bool compare(const matrix &item1, const matrix &item2);`

`vector<int>::iterator change_val(int val, vector<int>::iterator iter);`

## exercise 6.19

* (a) 非法。形参数量不匹配。

* (b) 合法。

* (c) 合法。

* (d) 合法。

## exercise 6.20

当函数不需要通过形参修改实参时，引用形参应该是常量引用。

常量对象将无法作为该函数的实参，一些本该合法的调用变成非法。

## exercise 6.21

``` c++
int bigger(int val1, int *val2)
{
    return (val1 > *val2) ? val1 : *val2;
}
```

## exercise 6.22

``` c++
void swap_ptr(int **ptr1, int **ptr2)
{
    auto temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

## exercise 6.23

## exercise 6.24

这个函数有潜在的风险。

形参虽然声明为长度为10的数组，但是实参有可能没有这么多元素。一旦实参数组的长度小于形参的声明，那么下标运算符就会越界，输出的值是未定义的。

可以将函数声明改为`void print(const int &ia[10])`

## [exercise 6.25](./6_25.cc)

## [exercise 6.26](./6_26.cc)

## exercise 6.27

``` c++
int sum(initializer_list<int> il)
{
    int total = 0;
    for(auto beg = il.begin(); beg != il.end(); ++beg)
    {
        total += *beg;
    }
    return total;
}
```

## exercise 6.28

`elem: const string &`

## exercise 6.29

看情况。如果存储的数据类型的拷贝操作很慢，可以考虑使用引用。

## exercise 6.30

## exercise 6.31

当引用绑定的对象是函数体内的局部变量时，返回的引用是无效的。

## exercise 6.32

合法。数组是在函数体之外定义的，所以返回的引用是有效的。

## [exercise 6.33](./6_33.cc)

## exercise 6.34

如果参数为正，会多递归一次，但是结果是一样的。

如果参数为负，则`val`会减到最小负数，然后因为环绕变成最大正数，继续减少直到变成0，最后的结果是无意义的。

## exercise 6.35

`val`的值将不会改变，递归会无限循环下去。

## exercise 6.36

`string (&func())[10];`

## exercise 6.37

类型别名：
``` c++
using strVec = string[10];
strVec& func();
```

尾置返回类型：
`auto func() -> string(&)[10];`

`decltype`：
``` c++
string a[10];
decltype((a)) func();
```

## exercise 6.38

* (a) `顶层const`不能区分函数重载。

* (b) 返回类型不能区分函数重载。

* (c) 合法。

## exercise 6.40

* (a) 合法。

* (b) 非法。拥有默认实参的形参右边不可以存在没有默认实参的形参。

## exercise 6.41

* (a) 非法。形参`ht`缺少实参。

* (b) 合法。

* (c) 与程序员的初衷不符。因为`char`可以隐式类型转换为`int`，所以调用是合法的。但是实参`'*'`显然是想初始化形参`bckgrnd`。

## exercise 6.42

``` c++
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}
```

## exercise 6.43

* (a) 声明和定义都放在头文件中，因为该函数是内联函数。

* (b) 声明放在头文件中，定义放在源文件中，为了避免多次定义。

## exercise 6.44

``` c++
inline bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}
```

## exercise 6.45

## exercise 6.46

不能。

因为不能保证形参一定是常量表达式。如果形参引用一个字符串字面值，那么函数的返回结果可以用于常量表达式；如果形参引用一个普通的`string`对象，那么函数的返回结果当然不可以用于常量表达式。

## exercise 6.47

## exercise 6.48

不合理。输入流的状态变为无效是一件很自然的事情，而`assert`应该检测那些不应该发生的事情。

## exercise 6.49

候选函数：与被调用函数重名，且在调用点可见的函数集合。

可行函数：可以在调用点被成功调用的函数集合。

## exercise 6.50

* (a) 调用失败。因为二义性。

* (b) 调用`f(int)`。

* (c) 调用`f(int, int)`。

* (d) 调用`f(double, double)`。

## exercise 6.51

## exercise 6.52

* (a) 通过类型提升实现的匹配。

* (b) 通过算术类型转换实现的匹配。

## exercise 6.53

* (a) 产生函数重载。

* (b) 产生函数重载。

* (c) 非法。`顶层const`不能区分函数重载。

## exercise 6.54

``` c++
int func(int, int);
vector<int(*)(int, int)> vec;
```

## [exercise 6.55 && exercise 6.56](./6_55.cc)