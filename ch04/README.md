## exercise 4.1

`5 + 10 * 20 / 2 = 105`

## exercise 4.2

* (a) `*(vec.begin())`

* (b) `(*(vec.begin())) + 1`

## exercise 4.3

可以接受。

在编码时避免依赖求值顺序不是一件非常复杂的事。只要遵循基本的原则，代码就不容易出错，效率也会很高。

## exercise 4.4

`((12 / 3) * 4) + (5 * 15) + ((24 % 8) / 2)`

## exercise 4.5

* (a) -86

* (b) -18

* (c) 42

* (d) -2

## exercise 4.6

`True`为偶数，`False`为奇数。

`return x % 2 == 0 ? True : False;`

## exercise 4.7

溢出就是某个值超出了它的数据类型可以表示的数值范围。

假设`int`为32位。

`0x80000000 - 1`

`0x7fffffff + 1`

`0x7fffffff * 0x7fffffff`

## exercise 4.8

逻辑与：只有左运算对象的值位真，才求右运算对象的值。

逻辑或：只有左运算对象的值为假，才求右运算对象的值。

## exercise 4.9

先判断`cp`是否是一个空指针，如果不是再判断`cp`是否指向一个空字符。

## exercise 4.10

`while(cin >> i && i != 42)`

## exercise 4.11

`a > b && b > c && c > d`

## exercise 4.12

先判断`i`和`j`的相等性，再判断相等性结果是否小于`k`

## exercise 4.13

* (a) `d = i = 3`

* (b) `i = 3, d = 3.5`

## exercise 4.14

第一个表达式非法，赋值运算符的左侧运算对象必须是一个可修改的左值。

第二个表达式，只要`i`的数据类型与`int`相容，条件判断就一定为真。

## exercise 4.15

指针类型与算术类型无法进行类型转换。

## exercise 4.16

* (a) 比较运算符的优先级比赋值高，所以`p`的值不是`True`就是`False`。可以改为`if((p = getPtr()) != 0)`

* (b) 一定不要将赋值语句作为条件判断。可以改为`if(i == 1024)`

## exercise 4.17

前置运算符返回改变后的对象，返回左值。

后置运算符返回对象原来的值，返回右值。

## exercise 4.18

前置运算符和解引用运算符符合右结合律，所以会先移动迭代器再解引用。

## exercise 4.19

* (a) 检查`ptr`是否是一个空指针，然后检查`ptr`指向的值是否为0，然后向后移动`ptr`。

* (b) 检查`ival`是否为0，将`ival`加1之后，再检查`ival`是否为0。

* (c) 不正确。这个表达式依赖求值顺序，可以改为`vec[ival] <= vec[ival + 1]`

## exercise 4.20

* (a) 合法。递增`iter`，然后解引用`iter`之前的值。

* (b) 合法。解引用`iter`，然后将结果递增，返回之前的结果。

* (c) 非法。成员选择运算符的优先级解引用运算符高，而对迭代器进行成员选择是非法的。

* (d) 合法。调用`iter`指向的`string`对象的`empty`成员函数。

* (e) 合法。解引用`iter`，然后将结果递增，返回递增之后的对象。

* (f) 合法。递增`iter`，然后对`iter`原来的值调用`empty`函数。

## exercise 4.21

``` c++
vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
for(auto &item : vec)
{
    item = item % 2 == 0 ? item : item * 2;
}
```

## [exercise 4.22.1](./4_22_1.cc) | [exercise 4.22.2](./4_22_2.cc)

使用`if`版本的更容易理解。因为如果条件运算符，需要层层嵌套。

## exercise 4.23

使用条件运算符一定要记得加括号。

可以改为`string pl = ((s + s[s.size() - 1] == 's') ? "" : "s);`

## exercise 4.24

如果满足左结合律，表达式将变为`finalgrade = ((grade > 90) ? "high pass" : (grade < 60)) ? "fail" : "pass";`

如果`grade > 90`，则`finalgrade`的值会变成'"fail"'，这显然是不对的。

## exercise 4.25

最终的结果是未定义的。

## exercise 4.26

如果`unsigned int`是32位，那没什么区别，否则，结果是未定义的。

## exercise 4.27

* (a) 3

* (b) 7

* (c) True

* (d) True

## exercise 4.28

## exercise 4.29

机器位数不同，第二个表达式的值是不一样的。

## exercise 4.30

* (a) `(sizeof x) + y`

* (b) `sizeof (p->mem[i])`

* (c) `(sizeof a) < b`

* (d) `sizeof (f())`

## exercise 4.31

没什么区别，都一样的。

## exercise 4.32

使用指针遍历整个数组。

## exercise 4.33

## exercise 4.34

* (a) `float -> bool`

* (b) `int -> float`、`float -> double`

* (c) `char -> int`、`int -> double`

## exercise 4.35

* (a) `char -> int`、`int -> char`

* (b) `int -> double`、`unsigned int -> double`、`double -> float`

* (c) `unsigned int -> float`、`float -> double`

* (d) `int->double`、`float -> double`、`double -> char`

## exercise 4.36

`i = i * static_cast<int>(d);`

## exercise 4.37

* (a) `pv = static_cast<void*>(const_cast<string*>(ps));`

* (b) `i = static_cast<int>(*pc);`

* (c) `pv = static_casr<void*>(&d);`

* (d) `pc = static_cast<char*>(pv);`

## exercise 4.38

将`j / i`的结果强制类型转换为`double`，用于初始化`slope`。