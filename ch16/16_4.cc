#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename _itTy, typename _vTy>
const _itTy my_find(const _itTy &beg, const _itTy &end, const _vTy &value)
{
    auto new_beg = beg;
    while(new_beg != end)
    {
        if(*new_beg == value)   return new_beg;
        ++new_beg;
    }
    return end;
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6};
    std::list<std::string> li = {"ni", "hao"};
    auto ret1 = my_find(vec.cbegin(), vec.cend(), 3);
    auto ret2 = my_find(li.cbegin(), li.cend(), "guo");
    std::cout << (ret1 == vec.end()) << std::endl;
    std::cout << (ret2 == li.end()) << std::endl;
    return 0;
}
