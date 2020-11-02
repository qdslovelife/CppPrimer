#include <iostream>
#include <vector>

void print(std::vector<int>::const_iterator beg, std::vector<int>::const_iterator end)
{
    if(beg == end)  return;
    std::cout << *beg << " ";
    print(++beg, end);
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    print(vec.cbegin(), vec.cend());
    return 0;
}