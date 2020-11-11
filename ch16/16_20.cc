#include <iostream>
#include <vector>

template <typename _Ty>
void print(_Ty &container)
{
    using const_iterator = typename _Ty::const_iterator;
    const_iterator beg = container.cbegin();
    const_iterator ed = container.cend();
    while(beg != ed)
    {
        std::cout << *beg << " ";
        ++beg;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,0};
    print(vec);
    return 0;
}