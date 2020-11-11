#include <iostream>

template <typename _Ty>
std::ostream& print(std::ostream &os, const _Ty &t)
{
    return os << t;
}

template <typename _Ty, typename... Args>
std::ostream& print(std::ostream &os, const _Ty &t, const Args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}

int main()
{
    print(std::cout, 1, 2, 3, 4, 5);
    return 0;
}