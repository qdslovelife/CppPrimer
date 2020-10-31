#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    auto it = vec.begin();
    while(it != vec.end())
    {
        *it = *it * 2;
        ++it;
    }
    for(const auto &item : vec)
    {
        std::cout << item << std::endl;
    }
    return 0;
}