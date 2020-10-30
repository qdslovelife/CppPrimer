#include <iostream>

int main()
{
    int val1, val2;
    std::cout << "Input two numbers: ";
    std::cin >> val1 >> val2;
    if(val1 > val2)
    {
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }
    while(val1 <= val2)
    {
        std::cout << val1 << std::endl;
        ++val1;
    }
    return 0;
}