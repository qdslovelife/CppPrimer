## exercise 12.1

都包含四个元素：`"a", "an", "the", "about"`

## exercise 12.2 | [Header](./strblob.h) & [Source](./strblob.cc)

## exercise 12.3

不需要。这两个函数都需要调用容器类型的相应函数，而`vector`的相应函数没有`const`重载，所以不需要。

## exercise 12.4

`size()`返回类型是一个无符号整数，其值一定大于等于0。

## exercise 12.5

优点：可以避免不符合程序员本意的`StrBlob`对象生成。

缺点：无法使用花括号列表直接生成一个`StrBlob`对象。

## [exercise 12.6](./12_6.cc)

## [exercise 12.7](./12_7.cc)

## exercise 12.8

将变量`p`转换为`bool`类型之后，原来指向的动态内存就会泄漏，因为已经没有别的指针指向这块内存了。

## exercise 12.9

变量`r`原来指向的动态内存泄漏，因为已经没有别的指针指向这块内存了。

使用智能指针就不会有内存泄漏，因为`r2`在赋值之后，其原来的引用计数变为0，此时会自动释放指向的动态内存。

## exercise 12.10

正确。使用智能指针去初始化另一个智能指针，这两个智能指针共享相同的内存，所以调用不会出错。

## exercise 12.11

错误。使用智能指针的原始指针去初始化一个智能指针，虽然两个智能指针指向相同的内存，但是引用计数不共享。一旦调用结束，内存就会被释放，就会出现空悬指针。

## exercise 12.12

* (a) 合法。

* (b) 非法。普通指针不能隐式类型转换为智能指针。

* (c) 非法。普通指针不能隐式类型转换为智能指针。

* (d) 合法。但是调用结束之后，指针`p`指向的内存就会被释放，`p`就变成空悬指针。

## exercise 12.13

`sp`指向的内存被释放，当`sp`被销毁时，指向的内存就会被第二次`delete`。

## exercise 12.14

## exercise 12.15

`shared_ptr<connection> p (&c, [](connection *p){ disconnect(*p); });`

## exercise 12.16

## exercise 12.17

* (a) 非法。`ix`不是一个指针。

* (b) 可能导致后续错误。`pi`不是指向动态内存。

* (c) 合法。

* (d) 可能导致后续错误。`&ix`不是动态内存。

* (e) 合法。

* (f) 可能导致后续错误。不要使用`get()`返回的普通指针去初始化一个智能指针。

## exercise 12.18

因为`shared_ptr`是共享动态内存的，与函数`release`的语义不符。

## exercise 12.19 | [Header](./strblob.h) & [Source](./strblob.cc)

## [exercise 12.20](./12_20.cc)

## exercise 12.21

之前版本的比较好。虽然代码写的多了，但是意图更加清晰，比较容易理解。

## exercise 12.22

构造函数的参数声明为`const`即可。

## [exercise 12.23](./12_23.cc)

## exercise 12.24

## exercise 12.25

`delete [] pa;`

## [exercise 12.26](./12_26.cc)

## exercise 12.27 | [Header](./text_query.h) & [Source](./text_query.cc)

## [exercise 12.28](./12_28.cc)

## exercise 12.29

就这个题来说，两种循环都是一样的，因为都是无限循环。

## [exercise 12.30](./12_30.cc)

## exercise 12.31

`set`的查询操作比`vector`要快很多，所以如果输入文件非常大，那么二者之间的效率差别就会比较明显。

所以，这里用`set`是要优于`vector`。

## exercise 12.32

## exercise 12.33 | [Header](./text_query.h) & [Source](./text_query.cc)