#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    auto iter1 = vec.cbegin() - 1, iter2 = vec.cend() - 1;
    while(iter2 != iter1)
    {
        std::cout << *iter2 << " ";
        --iter2;
    }
    return 0;
}