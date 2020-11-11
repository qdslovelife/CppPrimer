#include <iostream>

template <typename _Ty, unsigned size>
_Ty* begin(_Ty (&vec)[size])
{
    return &vec[0];
}

template <typename _Ty, unsigned size>
_Ty* end(_Ty (&vec)[size])
{
    return &vec[0] + size;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,0};
    auto beg = begin(a);
    auto ed = end(a);
    while(beg != ed)
    {
        std::cout << *beg << " ";
        ++beg;
    }
    std::cout << std::endl;
    return 0;
}