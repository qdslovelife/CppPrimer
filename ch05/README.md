## exercise 5.1

只有分号没有表达式的语句就是空语句

空语句被用在语法上需要一条语句但是逻辑上不需要的地方。

## exercise 5.2

块是由一组花括号括起来的、多条语句组合在一起的序列。

块用在语法上需要一条语句但是逻辑上需要多条语句的地方。

## exercise 5.3

``` c++
while(sum += val, val++ < 10)
    ;
```

可读性降低了，而且代码更容易出错。

## exercise 5.4

* (a) 先定义变量`iter`，再进入循环。

* (b) 在`while`循环的前面定义`status`，然后才能在`if`中使用该变量。

## [exercise 5.5](./5_5.cc)

## [exercise 5.6](./5_6.cc)

## exercise 5.7

* (a) 缺少分号。

* (b) 缺少花括号。

* (c) `ival`在第一个`if`结束后就已经被销毁。

* (d) 可以改为`ival == 0`

## exercise 5.8

`if`分支多于`else`分支时会出现`悬垂else`。

规定`else`分支匹配离它最近的未被匹配的`if`。

## [exercise 5.9](./5_9.cc)

## [exercise 5.10](./5_10.cc)

## [exercise 5.11](./5_11.cc)

## [exercise 5.12](./5_12.cc)

## exercise 5.13

* (a) 需要加`break`。

* (b) 可能会使用未声明的变量。

* (c) 如果想合并多个情况，只能写多个`case`标签。

* (d) `case`标签必须是常量表达式。

## [exercise 5.14](./5_14.cc)

## exercise 5.15

* (a) `ix`在`if`中是未声明的。

* (b) `for`循环缺少初始化部分。

* (c) 如果`sz`值为0，则会无限循环。

## exercise 5.16

我倾向于使用`while`循环，因为`while`的形式更加灵活。

## [exercise 5.17](./5_17.cc)

## exercise 5.18

* (a) 缺少花括号。

* (b) 不能将变量声明放在`do`的条件部分。

* (c) 条件部分使用的变量必须定义在循环体之外。

## exercise 5.19

``` c++
string s1, s2;
do
{
    cout << "Input two strings: ";
    cin >> s1 >> s2;
    const string &s = s1.size() > s2.size() ? s2 : s1;
    cout << s << endl;
}while(1);
```

## [exercise 5.20](./5_20.cc)

## [exercise 5.21](./5_21.cc)

## exercise 5.22

``` c++
for(int sz = get_size(); sz <= 0; sz = get_size())
    ;
```

## [exercise 5.23](./5_23.cc)

## exercise 5.24

## [exercise 5.25](./5_25.cc)