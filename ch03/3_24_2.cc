#include <vector>
#include <iostream>

int main()
{
    int i;
    std::vector<int> vec;
    std::vector<int>::iterator beg;
    std::vector<int>::iterator last;
    while(std::cin >> i)
    {
        vec.push_back(i);
    }
    beg = vec.begin();
    last = vec.end() - 1;
    while(beg < last)
    {
        std::cout << *beg + *last << std::endl;
    }
    if(beg == last)
    {
        std::cout << *beg << std::endl;
    }
    return 0;
}