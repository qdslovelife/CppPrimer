#include <iostream>

int main()
{
    int val = 10;
    while(val >= 0)
    {
        std::cout << val << std::endl;
        --val;
    }

    for(val = 10; val >= 0; --val)
    {
        std::cout << val << std::endl;
    }
    return 0;
}