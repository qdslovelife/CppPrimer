#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    std::list<int> back, front, insert;
    auto ib = std::back_inserter(back);
    auto iif = std::front_inserter(front);
    auto ii = std::inserter(insert, insert.begin());
    for(auto num : vec)
    {
        *ib = num;
        *iif = num;
        *ii = num;
    }
    for(auto num : back)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    for(auto num : front)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    for(auto num : insert)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}