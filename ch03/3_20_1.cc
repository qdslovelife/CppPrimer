#include <iostream>
#include <vector>

int main()
{
    int i;
    int index;
    std::vector<int> vec;
    while(std::cin >> i)
    {
        vec.push_back(i);
    }

    index = 0;
    while(index < vec.size() - 1)
    {
        std::cout << vec[index] + vec[index + 1] << std::endl;
        index += 2;
    }
    while(index < vec.size())
    {
        std::cout << vec[index] << std::endl;
        ++index;
    }
    return 0;
}