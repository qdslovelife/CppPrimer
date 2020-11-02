#include <iostream>
#include "Chapter6.h"

int main()
{
    int val;
    std::cout << "input one interger: ";
    std::cin >> val;
    std::cout << "The fact of input is " << fact(val) << std::endl;
    return 0;
}