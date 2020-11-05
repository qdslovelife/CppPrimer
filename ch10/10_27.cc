#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1,2,3,2,1,2,4,5,6,5,6,7,8,7,8,9};
    std::list<int> l;
    auto iter = std::back_inserter(l);
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.begin(), vec.end(), iter);
    for(auto num : l)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}