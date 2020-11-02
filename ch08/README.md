## exercise 8.1

``` c++
istream& func(istream& is)
{
    int i;
    while(is >> i)
    {
        cout << i;
    }
    is.clear();
    return is;
}
```

## exercise 8.2

## exercise 8.3

当标准输入流处于无效状态时，`while`循环会终止。

## [exercise 8.4](./8_4.cc)

## [exercise 8.5](./8_5.cc)

## [exercise 8.6](./8_6.cc)

## [exercise 8.7](./8_7.cc)

## [exercise 8.8](./8_8.cc)

## exercise 8.9

## [exercise 8.10](./8_10.cc)

## exercise 8.11

``` c++
string line, word;
vector<PersonInfo> people;
istringstream record;
while(getline(cin, line))
{
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while(record >> word)
    {
        info.phones.push_back(word);
    }
    people.push_back(info);
}
```

## exercise 8.12

因为程序一定会赋予对象新值，类内初始值是无意义的。

## exercise 8.13

## exercise 8.14

因为字符串拷贝浪费时间，所以定义为引用；因为程序不会修改它们的值，所以定义为`const`。