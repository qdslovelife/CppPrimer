#include <iostream>
#include <vector>

int main()
{
    int i;
    std::vector<int> vec;
    int low, high;
    while(std::cin >> i)
    {
        vec.push_back(i);
    }
    low = 0;
    high = vec.size() - 1;
    while(low < high)
    {
        std::cout << vec[low] + vec[high] << std::endl;
        ++low;
        --high;
    }
    if(low == high)
    {
        std::cout << vec[low] << std::endl;
    }
    return 0;
}