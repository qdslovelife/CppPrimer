## exercise 15.1

虚成员就是用`virtual`关键字生命的成员函数。这类成员在调用时执行动态绑定。

## exercise 15.2

`protected`成员可以被派生类访问，不能被其他使用基类的代码访问。

`private`成员只能被基类的成员和友元访问。

## exercise 15.3 | [Header](./quote.h)

## exercise 15.4

* (a) 非法。类不能继承自己。

* (b) 合法。

* (c) 类的声明中不包含它的派生列表。

## exercise 15.5 | [Header](./bulk_quote.h)

## [exercise 15.6](./15_6.cc)

## exercise 15.7 | [Header](./limit_quote.h)

## exercise 15.8

静态类型就是声明一个变量时使用的类型，表达式的静态类型在编译器是可知的。

动态类型只有在运行时才可以确定，并且动态类型与静态类型不符的情况只会发生在基类的引用和基类的指针。

## exercise 15.9

当程序将一个派生类对象或其地址赋值给一个基类引用或指针时，动态类型和静态类型时不同的。

``` c++
Bulk_Quote bulk_quote;
Limit_Quote limit_quote;
Quote &quote1 = bulk_quote;
Quote *quote2 = &bulk_quote;
Quote *quote3 = &limit_quote;
```

## exercise 15.10

`ifstream`公有派生自`istream`，所以当程序的形参为`istream&`时，我们可以用`ifstream`的对象去初始化该形参。

## [exercise 15.11](./15_11.cc)

## exercise 15.12

如果希望将基类的虚函数修改之后变成整个继承体系的最终版本，那么是有必要的。

## exercise 15.13

有问题。

派生类中如果想调用基类版本的虚函数，可以改成`base::print(os);`

## exercise 15.14

* (a) 基类。

* (b) 派生类。

* (c) 基类。

* (d) 派生类。

* (e) 基类。

* (f) 派生类。 

## exercise 15.15 | [Disc_Quote](./disc_quote.h) & [Bulk_Quote](./new_bulk_quote.h)

## exercise 15.16 | [Header](./new_limit_quote.h)

## exercise 15.17

## exercise 15.18

1. 合法。

2. 非法。私有继承的派生类不能被当作基类使用。

3. 非法。受保护继承也不可以。

4. 合法。

5. 非法。基类中的公共成员访问不到，所以不能使用动态绑定。

6. 非法。受保护继承也不行。

## exercise 15.19

1. 合法。

2. 合法。

3. 合法。

4. 合法。

5. 非法。派生类的派生类无法访问基类的公共成员（因为派生类的私有继承），所以非法。

6. 非法。受保护继承也不行。

## [exercise 15.20](./15_20.cc)

## exercise 15.21

## exercise 15.22

## exercise 15.23

可以改为`int fcn() override;`

## exercise 15.24

作为基类的类需要定义一个虚析构函数。

## exercise 15.25

如果基类没有默认构造函数，那么编译器将不会为派生类合成默认构造函数。但是可以自己定义派生类的默认构造函数。

## exercise 15.26

## exercise 15.27 | [Header](./bulk_quote.h)

## exercise 15.28

## [exercise 15.29](./15_29.cc)

## [exercise 15.30](./15_30.cc) | [Header](./basket.h) & [Source](./basket.cc)

## [test_query.cc](./test_query.cc)