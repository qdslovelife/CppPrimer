## exercise 16.1

当代码使用函数模板或类模板生成相应的函数或类时，我们说发生了模板实例化。

当发生模板实例化时， 编译器生成相应的代码，就好像我们定义了一个相应的函数或者类一样。

## exercise 16.2

``` c++
template <typename _Ty>
bool compare(const T &lhs, const T &rhs)
{
    return lhs < rhs;
}
```

## exercise 16.3

## [exercise 16.4](./16_4.cc)

## exercise 16.5

``` c++
template <typename _Ty, unsigned size>
void print(const _Ty (&vec)[size])
{
    for(const auto &item : vec)
    {
        cout << item << endl;
    }
}
```

## [exercise 16.6](./16_6.cc)

## [exercise 16.7](./16_7.cc)

## exercise 16.8

大部分类都会实现不相等运算符和相等运算符，因为它们的语义比较容易确定。

有些类类型很难定义比较运算符，因为如果类类型是现实世界某个物体的抽象，那么很难定义一个严格弱序确定谁打谁小。

## exercise 16.9

函数模板实例化之后会生成一个函数的定义的代码。

类模板实例化之后会生成一个类以及类的成员函数的定义的代码。

## exercise 16.10

类的定义会生成代码。

类的被调用的成员函数也会实例化，生成对应的代码。

## exercise 16.11

在类模板中使用其他模板时，一般使用自己的模板参数去作为其他模板的模板实参。

即，我们需要为`ListItem`加上模板实参。

## exercise 16.12

## exercise 16.13

一对一友好关系，只有相同类型的`BlobPtr`才可以比较。

## exercise 16.14

## exercise 16.15

## exercise 16.16

## exercise 16.17

没什么不同。

当我们想要告诉编译器类型参数的一个成员表示一个类型时，只能使用`typename`。

## exercise 16.18

* (a) 每个模板参数都要声明是类型参数还是非类型参数。

* (b) 不能重声明模板参数。

* (c) `inline`关键字应该放在`template <typename T>`之后。

* (d) 没有声明返回类型。

* (e) 合法。但是最好不要重名。

## [exercise 16.19](./16_19.cc)

## [exercise 16.20](./16_20.cc)

## exercise 16.21 | [debug_delete](./debug_delete.cc)

## exercise 16.22

## exercise 16.23

当函数`runQueries`返回时，`TextQuery`对象被销毁，此时执行调用运算符。

## exercise 16.24

## exercise 16.25

第一个声明一个使用`string`实例化的`vector`。

第二个实例化`vector<string>`，并且实例化其所有成员函数。

## exercise 16.26

如果我们想要默认初始化`vector<NoDefault>`，编译器会报错。

## exercise 16.27

* (a) 没有实例化。因为这只是一个函数声明。

* (b) 没有实例化。引用不需要实例化。

* (c) 使用`int`实例化。

* (d) 没有实例化。指针不需要实例化。

* (e) 使用`char`实例化。

* (f) 使用`string`实例化。

## exercise 16.28 | [shared_ptr](./my_shared_ptr.h) & [unique_ptr](./my_unique_ptr.h)

## exercise 16.29

## exercise 16.30

## exercise 16.31

## exercise 16.32

在模板参数推导过程中，编译器使用调用中的参数类型来查找模板参数，这些模板参数生成与给定调用最匹配的函数版本。

## exercise 16.33

非`const`向`const`的转换

函数向指针的转换。

## exercise 16.34

* (a) 非法。两个字符数组的长度不相同。

* (b) 合法。`T`为`const char[4]`。

## exercise 16.35

* (a) 合法。`T`是`char`。

* (b) 合法。`T`是`double`。

* (c) 合法。`T`是`char`。

* (d) 非法。`T`推断为`double`、`float`，类型不相同。

## exercise 16.36

* (a) `T`是`int *`。

* (b) 两个都是`int *`。

* (c) `T`是`const int *`。

* (d) 两个都是`const int *`。

* (e) 非法。

* (f) `T1`是`int *`，`T2`是`const int *`。

## exercise 16.37

可以，只要我们指定显式模板实参：`max<double>(a, b);`。

## exercise 16.38

因为`make_shared`的函数形参的数量是不确定的，无法进行模板实参推断，所以必须指定显示模板实参。

## exercise 16.39

可以改为：`compare<string>("ni", "hao")`。

## exercise 16.40

合法。但是迭代器引用的类型必须支持与整数的加法运算符。返回类型依赖于加法运算符的返回类型。

## exercise 16.41

## exercise 16.42

* (a) `T`：`int&`；`val`：`int&`。

* (b) `T`：`const int&`；`val`：`const int&`。

* (c) `T`：`int`；`val`：`int&&`。

## exercise 16.43

`T`：`int&`。

## exercise 16.44

这两个问题的答案相同，不论哪种调用，`T`均为`int`。

## exercise 16.45

如果使用字面常量调用`g`，则`T`被推断为`int`，调用合法。

如果使用变量调用`g`，则`T`被推断为`int&`，调用合法。

## exercise 16.46

将`elem`指向的元素转变为右值，然后调用移动构造函数将元素的值移动到`dest`指向的元素。最后，将`elem`和`dest`指向下一个元素，继续循环。

## exercise 16.47

## exercise 16.48

## exercise 16.49

## exercise 16.50

## exercise 16.51

## [exercise 16.52](./16_52.cc)

## [exercise 16.53](./16_53.cc)

## exercise 16.54

编译会失败。

## exercise 16.55

如果非可变参数版本声明在可变参数版本之前，则编译会失败。

假设可变参数包一开始有5个参数，则递归调用5次之后可变参数包会变为空，此时没有实参可以用来初始化函数形参`t`，而函数形参`t`没有默认实参，所以编译会失败。

## exercise 16.56

## exercise 16.57

可变参数版本的优点是可以接受不同类型的实参，缺点是为了输出不同类型的实参我们需要定义一些辅助函数。

## exercise 16.58

## exercise 16.59

## exercise 16.60

`make_shared`有一个需要显式模板实参的模板参数和一个可变参数包。

该函数将可变参数包的所有参数转发给显式模板实参的构造函数以构造对象。

## exercise 16.61

``` c++
template <typename _Ty, typename... Args>
shared_ptr<_Ty> make_shared(Args&&... var)
{
    return shared_ptr<_Ty>(new _Ty(forward<Args>(args)...));
}
```

