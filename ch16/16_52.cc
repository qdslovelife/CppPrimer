#include <iostream>
#include <string>

template <typename _Ty, typename... Args>
void foo(const _Ty &t, const Args&... rest)
{
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(rest) << std::endl;
}

int main()
{
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";
    foo(i,s,42,d);
    foo(s,42,"hi");
    foo(d,s);
    foo("hi");
}