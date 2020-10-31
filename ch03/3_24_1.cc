#include <iostream>
#include <vector>

int main()
{
    int i;
    std::vector<int> vec;
    std::vector<int>::iterator it;
    while(std::cin >> i)
    {
        vec.push_back(i);
    }

    it = vec.begin();
    while(it != vec.end() - 1)
    {
        std::cout << *it + *(it + 1) << std::endl;
        it = it + 2;
    }
    while(it != vec.end())
    {
        std::cout << *it << std::endl;
    }
    return 0;
}