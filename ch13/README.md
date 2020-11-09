## exercise 13.1

拷贝构造函数首先是一个构造函数，然后该函数的第一个形参类型是自身类类型的引用，其他形参都有默认实参。

当编译器通过拷贝初始化生成一个类类型对象时，会调用拷贝构造函数。

## exercise 13.2

拷贝构造函数的第一个形参必须是自身类类型的引用，且最好是`const`。

## exercise 13.3

因为这两个类的成员都是由标准库或`C++`定义的，它们都实现了自己的拷贝控制成员，所以合成的默认构造函数是可以使用的。

合成的默认构造函数会依次拷贝所有类成员。

## exercise 13.4

1. `foo_bar`的形参初始化。

2. `local`的初始化。

3. 动态分配内存以生成一个`Point`类型时。

4. 5. 使用列表初始化时。

6. `foo_bar`返回时。

## exercise 13.5

``` c++
HasPtr(const HasPtr &item)
    : ps(new string(*item.ps)), i(item.i)
{}
```

## exercise 13.6

拷贝赋值运算符定义了当使用一个类类型对象对另一个类类型对象赋值时所执行的操作。

正如定义所言，当对一个类类型对象赋值时会调用拷贝赋值运算符。

合成的拷贝赋值运算符在可行的情况下，会依次赋值类的每个成员。

如果类未定义自己的拷贝赋值运算符，编译器会生成一个合成的拷贝赋值运算符。

## exercise 13.7

因为两个类的成员都定义了拷贝赋值运算符，所以类的赋值会将每个成员都进行赋值。

## exercise 13.8

``` c++
HasPtr& operator=(const HasPtr &item)
{
    if(this == &item)   return *this;
    delete this->ps;
    ps = new string(*(item.ps));
    i = item.i;
    return *this;
}
```

## exercise 13.9

析构函数定义了当对象被销毁时做什么。

合成析构函数什么都不做，只会在析构部分销毁每个成员。

当类未定义自己的析构函数时，编译器会生成一个合成的析构函数。

## exercise 13.10

会调用`shared_ptr`和`weak_ptr`的析构函数。

## exercise 13.11

``` c++
~HasPtr
{
    delete ps;
}
```

## exercise 13.12

三次。

1. 形参`accum`销毁时。

2. 局部变量`item1`销毁时。

3. 局部变量`item2`销毁时。

## [exercise 13.13](./13_13.cc)

我经常忽略的一个地方就是函数返回时会进行拷贝，生成一个临时对象（匿名对象），而这个临时对象也会进行析构。因为是匿名的，所以如果不仔细的话比较容易忽视。

## exercise 13.14

输出的`mysn`是一样的，因为合成的拷贝构造函数只是简单地拷贝所有数据成员。

## exercise 13.15

会。因为程序初始化`b`和`c`时使用的是拷贝构造函数。

## exercise 13.16

会。与上一题的结果不同，因为每个变量都少拷贝一次。

## exercise 13.17

## exercise 13.18 | [Header](./employee.h) & [Source](./employee.cc)

## exercise 13.19 | [Header](./employee.h) & [Source](./employee.cc)

需要。因为每个雇员证号都是唯一的，所以需要拷贝构造函数和拷贝赋值函数，但是并不需要析构函数。

## exercise 13.20

每个数据成员会调用自己的拷贝控制成员。

## exercise 13.21

不需要。因为这两个类使用的是标准库容器，它们都有良好定义的拷贝控制成员，所以不需要我们再去管理资源。

## exercise 13.22

``` c++
HasPtr(const HasPtr &item)
    : ps(new string(*item.ps)), i(item.i)
{}

HasPtr& operator=(const HasPtr &item)
{
    if(this == &item)   return *this;
    delete ps;
    ps = new string(*(item.ps));
    i = item.i;
    return *this;
}
```

## exercise 13.23

记得处理自赋值的情况。

## exercise 13.24

如果未定义析构函数，则当对象被销毁时会发生内存泄漏。

如果未定义拷贝构造函数，则当进行拷贝初始化时类的行为是类指针的。

## exercise 13.25

拷贝构造函数和拷贝赋值函数会将智能指针指向新的内存，而不是共享。

因为智能指针已经定义了析构函数来管理资源，所以我们的类就不需要定义析构函数了。

## exercise 13.26

``` c++
StrBlob::StrBlob(const StrBlob &item)
    : data_(make_shared<vector<string>>(*item.data_))
{}

StrBlob& StrBlob::operator=(const StrBlob &item)
{
    if(this == &item)   return *this;
    data_.~shared_ptr();
    data_ = make_shared<vector<string>>(*item.data_);
    return *this;
}
```

## exercise 13.27

## exercise 13.28

* (a)

``` c++
TreeNode()
    : value(), count(1), left(nullptr), right(nullptr)
{}

TreeNode(const TreeNode &item)
    : value(item.value), count(item.count), left(new TreeNode(*item.left)), right(new TreeNode(*item.right))
{}

TreeNode& operator=(const TreeNode &item)
{
    if(this == &item)   return *this;
    this->~TreeNode();
    left = new TreeNode(*item.left);
    right = new TreeNode(*item.right);
    value = item.value;
    count = item.count;
    return *this;
}

~TreeNode()
{
    if(left)   
    {
        delete left;
        left = nullptr;
    }
    if(right)
    {
        delete right;
        right = nullptr;
    }
}
```

* (b)
``` c++
BinStrTree() 
    : root(nullptr)
{}

BinStrTree(const BinStrTree &item)
    : root(new TreeNode(*item.root))
{}

BinStrTree& operator=(const BinStrTree &item)
{
    if(this == &item)   return *this;
    delete root;
    root = new TreeNode(*item.root);
    return *this;
}
```

## exercise 13.29

`HasPtr`的数据成员都是内置类型，与我们定义的`swap`函数的形参类型不匹配，所以会调用标准库的`swap`函数。标准库的`swap`函数只是简单地使用拷贝和赋值来交换两个形参，所以不会递归循环。

## exercise 13.30

``` c++
void HasPtr(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "swap(HasPtr &, HasPtr &)" << endl;
}
```

## exercise 13.31

## exercise 13.32

会受益。拷贝构造函数会进行内存分配，拷贝赋值运算符会进行一次析构和一次拷贝构造，而`swap`函数不涉及内存管理，所以函数性能会快一些。

## exercise 13.33

因为我们要通过形参去修改作为实参的`Folder`对象，所以既不能是拷贝也不能是`const`。

## exercise 13.34 | [Header](./message.h) & [Source](./message.cc)

## exercise 13.35

将会出现不同步的现象。有两个`Message`对象记录自己已经添加到了一个`Folder`中，但是这个`Folder`对象只记录了一个`Message`对象。

## exercise 13.36 | [Header](./message.h) & [Source](./message.cc)

## exercise 13.37 | [Header](./message.h) & [Source](./message.cc)

## exercise 13.38

因为`swap`函数会将拷贝赋值运算符的形参从多个`Folder`对象中删除，然后再添加到多个`Folder`对象中，这些操作完全是不必要的，所以我们不使用拷贝并交换方式。

## exercise 13.39 | [Header](./strvec.h) & [Source](./strvec.cc)

## exercise 13.40 | [Header](./strvec.h) & [Source](./strvec.cc)

## exercise 13.41

因为`first_free_`是指向尾后的指针，我们要在它当前指向的位置构造元素。如果使用前置就会空过一些内存，当析构该对象时就会出错。

## exercise 13.42

## exercise 13.43

## exercise 13.44 | [Header](./my_string.h) & [Source](./my_string.cc)

## exercise 13.45

## exercise 13.46

* `r1`：右值引用。

* `r2`：左值引用。

* `r3`：左值引用。

* `r4`：右值引用。

## exercise 13.47

## [exercise 13.48](./13_48.cc) 

## exercise 13.49

## [exercise 13.50](./13_48.cc)

## exercise 13.51

`unique_ptr`可以执行移动操作。

## exercise 13.52

## exercise 13.53

因为右值的隐含含义就是即将被销毁，所以原始版本的赋值运算符会多调用一次析构函数来析构形参。

## exercise 13.54

赋值会有二义性。

## exercise 13.55

## exercise 13.56

因为`ret`作为变量是一个左值，所以`ret.sorted()`会调用左值限定的函数，这会导致无限递归。

## exercise 13.57

函数返回值是一个右值，所以会正确调用右值限定的成员函数。

## exercise 13.58