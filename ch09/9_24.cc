#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {1,2,3,4,5};
    std::cout << vec.at(0) << " "
              << vec[0] << " "
              << *vec.cbegin() << " "
              << vec.front() << std::endl;
    return 0;
}