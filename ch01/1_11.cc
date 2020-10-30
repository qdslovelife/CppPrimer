#include <iostream>

int main()
{
    int val1, val2;
    std::cout << "Input two numbers: ";
    std::cin >> val1 >> val2;
    while(val1 <= val2)
    {
        std::cout << val1 << std::endl;
        ++val1;
    }
    std::cout << "Input two numbers: ";
    std::cin >> val1 >> val2;
    for(; val1 <= val2; ++val1)
    {
        std::cout << val1 << std::endl;
    }
    return 0;
}