#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1,2,3,4,5,4,3,4,5,6,7,8,9,10};
    int i = 4;
    std::cout << std::count(vec.cbegin(), vec.cend(), i) << std::endl;
    return 0;
}