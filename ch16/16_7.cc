#include <iostream>

template <typename _Ty, unsigned size>
constexpr unsigned length(_Ty (&vec)[size])
{
    return size;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    int b[length(a)];
    return 0;
}