#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item si1, si2;
    std::cin >> si1 >> si2;
    if(si1.isbn() == si2.isbn())
    {
        std::cout << si1 + si2 << std::endl;
    }
    else
    {
        std::cout << "They must have same isbn." << std::endl;
    }
    return 0;
}