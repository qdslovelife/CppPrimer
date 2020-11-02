## exercise 7.1

## exercise 7.2 

## exercise 7.3

## exercise 7.4 && exercise 7.5 

应该是const，因为这两个函数不会修改类的成员变量。

## exercise 7.6 

## exercise 7.7

## exercise 7.8

`read`函数需要修改形参绑定的对象，而`print`函数不需要。

## exercise 7.9 

## exercise 7.10

相当于`if(cin >> data1 >> data2)`

## exercise 7.11

``` c++
SalesData();
SalesData("HarryPotter");
SalesData("HarryPotter", 10, 10);
SalesData(cin);
```

## exercise 7.12

## exercise 7.13

## exercise 7.14

## exercise 7.15

## exercise 7.16

对访问说明符出现的位置和次数没有限制。

类的公共接口应该定义在`public`说明符之后。

类的私有成员变量和函数应该定义在`private`说明符之后。

## exercise 7.17

只有一个区别：成员的默认访问权限不同。`class`默认是`private`，`struct`默认是`public`。

## exercise 7.18

* 提高类的可扩展性。

* 提高类的安全性。

## exercise 7.19

成员变量声明为`private`，构造函数和接口声明为`public`。

## exercise 7.21

当一个非类的成员的函数需要访问类的私有成员时需要用到友元。

友元的好处：可以减少类的成员函数的数量，降低类的对象的大小。

友元的坏处：破坏了类的封装。

## exercise 7.22

## exercise 7.23

## exercise 7.24

## exercise 7.25

可以。因为`string`类型定义了自己的拷贝和赋值操作，我们定义的类的默认行为可以依赖这些操作完成。

## exercise 7.26

## exercise 7.27

## exercise 7.28

造成的结果是：不能在这三个函数的返回对象上调用这三个函数，因为返回的是一个临时对象。

## exercise 7.29

## exercise 7.30

优点：可以更加清楚地理解函数到底在做什么。

缺点：太麻烦。

## exercise 7.31

``` c++
class X;
class Y;

class X { Y* mem; };
class Y { X mem; };
```

## exercise 7.32

## exercise 7.33

`pos`只有`Screen`类的作用域内才有效。可以改为`Screen::pos`。

## exercise 7.34

没什么情况发生。因为定义类时首先要编译成员的声明，所以成员的声明放在哪里都无所谓。

## exercise 7.35

首先`Type`已经是一个类型了， 类不可以重新定义改名字，所以这里非法。

其次，`setVal`函数调用的`initVal`是类的成员函数，而不是外层作用域中声明的`initVal`。

## exercise 7.36

成员的初始化顺序和它们在类定义中的出现顺序一致，所以这里的构造函数是非法的。

可以将构造函数初始值列表中的`base`和`rem`换个顺序。

## exercise 7.37

`first_item`：`SalesData(istream&)`

`next`：`SalesData()`

`last`：`SalesData(string&)`

## exercise 7.38

`SalesData(istream &is = cin);`

## exercise 7.39

非法。当我们以`SalesData item;`这种方式创建对象时会产生二义性，因为编译器发现有三个函数都是精确匹配的可行函数。

## exercise 7.40

## exercise 7.41

## exercise 7.42

## exercise 7.43

`C() : no_default(0) {}`

## exercise 7.44

非法。因为类`NoDefault`没有默认构造函数。

## exercise 7.45

合法。因为我们已经为类`C`定义了默认构造函数。

## exercise 7.46

* (a) 不正确。如果类没有定义构造函数，编译器在可行的情况下会为类合成一个默认构造函数。

* (b) 不正确。只要构造函数的所有形参都有默认实参，那么该构造函数也被视作默认构造函数。

* (c) 不正确。定义默认构造函数的益处比无意义的默认值的坏处要大得多，所以一定要定义默认构造函数。

* (d) 不正确。这个看情况，如果类成员没有默认构造函数，那么编译器是无法合成默认构造函数的。

## exercise 7.47

我认为不应该。

好处：代码简洁。

坏处：不是所有的字符串都可以被看作`SalesData`。

## exercise 7.48

没什么区别。两种情况都会调用那个构造函数。

## exercise 7.49

* (a) 正确。

* (b) 不正确。 因为我们无法获得临时对象的地址，所以临时对象是一个右值，而普通引用是无法绑定右值的，所以不正确。

* (c) 正确。但是成员函数修饰符`const`有问题，因为这和`combine`的函数语义相悖。

## exercise 7.50

没有。构造函数需要两个`string`类型的对象。

## exercise 7.51

因为`vector`存储的类型和`vector`类型本身的关系并不紧密。

当我们使用`10`时，不足以认为我们需要一个`vector`。

而当我们使用`"hello, world"`，我们总是可以用`string`代替C风格的字符串。

## exercise 7.52

没什么问题。但是`Sales_Data`并不是一个聚合类，因为聚合类没有类内初始值。

## exercise 7.53

## exercise 7.54

不应该。返回常量表达式的函数应该只存在一条返回语句，而且形参`b`也没办法保证是常量表达式。

## exercise 7.55

不是。`string`不是字面值类型。

## exercise 7.56

被声明为`static`的成员就是静态成员。

类的所有对象共享同一个静态成员。

## exercise 7.57

## exercise 7.58

如果静态成员使用类内初始值，则必须是字面值常量类型。

在类内初始化成员时，不能使用圆括号；否则，类无法分清这是在初始化成员还是在声明一个新的函数。可以使用花括号进行列表初始化。