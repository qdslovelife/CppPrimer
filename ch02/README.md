## exercise 2.1

* 区别在于位数不同。

* 区别在于最高位的解释不同。

* 区别在于位数不同。

## exercise 2.2

`double`，精度比较高。

## exercise 2.3 | exercise 2.4

`32 4294967264 32 -32 0 0`

## exercise 2.5

* (a) 字符字面值、宽字符字面值、字符串字面值、宽字符串字面值

* (b) `int、unsigned int、long、unsigned long`、八进制、十六进制

* (c) `double、float、long double`

* (d) `int、unsigned int、double、double`

## exercise 2.6

第一行是十进制。

第二个`month`非法，因为八进制中没有9。

第二个`day`是八进制。

## exercise 2.7

* (a) 字符串字面值

* (b) `long double`

* (c) `float`

* (d) `long double`

## exercise 2.8

``` c++
std::cout << "2M\n";
std::cout << 2 << '\t' << "M\n";
```

## exercise 2.9

* (a) 非法。先定义变量，然后再输入。

* (b) 非法。花括号初始化必须是精确匹配。

* (c) 非法。必须先声明wage。

* (d) 合法。

## exercise 2.10

`global_str`:空串。

`global_int`:0。

`local_int`:未初始化。

`local_str`:空串。

## exercise 2.11

* (a) 定义。

* (b) 定义。

* (c) 声明。

## exercise 2.12

* (a) 非法。

* (b) 合法。

* (c) 非法。

* (d) 非法。

* (e) 合法。

## exercise 2.13

`j = 100`

## exercise 2.14

`100 45`

## exercise 2.15

* (a) 合法。

* (b) 非法。普通引用的对象必须是一个左值。

* (c) 合法。

* (d) 非法。引用必须初始化。

## exercise 2.16

* (a) 合法。改变`d`的值。

* (b) 合法。发生隐式类型转换。

* (c) 合法。小数点被舍去。

* (d) 合法。小数点被舍去。

## exercise 2.17

`10 10`

## exercise 2.18

``` c++
int i = 0, j = 1;
int *p = &i;
*p = 2;
p = &j;
```

## exercise 2.19

最重要的区别就是指针是一个对象，而引用只是一个别名。

## exercise 2.20

对`i`求平方。

## exercise 2.21

* (a) 非法。普通指针指向的对象必须是一个左值。

* (b) 非法。`ip`只能存储地址值。

* (c) 合法。

## exercise 2.22

* 如果`p`不是一个空指针，则

* 如果`*p`不为0，则

## exercise 2.23

不能。指针可以指向几乎任何地方，没有办法确定是否指向一个合法对象。

## exercise 2.24

`void *`可以指向任何对象，而`long *`只能指向`long`对象。

## exercise 2.25

## exercise 2.26

* (a) 非法。常量必须初始化。

* (b) 合法。

* (c) 合法。

* (d) 非法。常量不能被赋值。

## exercise 2.27

* (a) 非法。普通引用必须绑定左值。

* (b) 合法。

* (c) 合法。

* (d) 合法。

* (e) 合法。

* (f) 非法。引用必须初始化。

* (g) 合法。

## exercise 2.28

* (a) 非法。常量指针必须初始化。

* (b) 非法。常量指针必须初始化。

* (c) 非法。常量必须初始化。

* (d) 非法。常量指针必须初始化。

* (e) 合法。

## exercise 2.29

## exercise 2.30

`v2`:顶层const。

`v1`:非const对象。

`p1`:非const对象。

`r1`:非const对象。

`p2`:底层const。

`p3`:顶层const加底层const。

`v2`:底层const，引用本身就是顶层const。

## exercise 2.31

* 非法。

* 非法。

* 合法。

* 非法。

* 合法。

## exercise 2.32

非法。`int null = 0, *p = nullptr;`

## exercise 2.33 | exercise 2.34

* `a`被改为42.

* `b`被改为42.

* `c`被改为42.

* 非法。`d`是一个指针。

* 非法。`e`是一个指针。

* 非法。`g`是一个绑定常量的引用，不能被赋值。

## exercise 2.35

``` c++
int j;
const int &k;
const int *p;
const int j2;
const int &k2;
```

## exercise 2.36

``` c++
int a : 4;
int b : 4;
int c : 4;
int &d : 4;
```

## exercise 2.37

``` c++
int a : 3;
int b : 4;
int c : 3;
int &d : 3;
```

## exercise 2.38

## exercise 2.39

## exercise 2.40

``` c++
struct SalesData
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

## exercise 2.41

## exercise 2.42