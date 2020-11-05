#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
    std::ostream_iterator<int> os_iter(std::cout, " ");
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    std::copy(vec.crbegin(), vec.crend(), os_iter);
    return 0;
}