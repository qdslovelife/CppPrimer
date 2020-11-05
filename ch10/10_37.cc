#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,0};
    auto iter1 = vec.crbegin() + 3, iter2 = vec.crend() - 2;
    std::list<int> l(iter1, iter2);
    std::ostream_iterator<int> os_iter(std::cout, " ");
    std::copy(l.cbegin(), l.cend(), os_iter);
    return 0;
}