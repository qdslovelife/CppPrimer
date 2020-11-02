#include <iostream>

int fact(int val)
{
    int ret = 1;
    while(val > 1)
    {
        ret *= val--;
    }
    return ret;
}

int main()
{
    int val;
    std::cout << "input one interger: ";
    std::cin >> val;
    std::cout << "The fact of input is " << fact(val) << std::endl;
    return 0;
}