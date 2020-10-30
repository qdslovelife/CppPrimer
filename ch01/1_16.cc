#include <iostream>

int main()
{
    int sum, cur;
    if(std::cin >> sum)
    {
        while(std::cin >> cur)
        {
            sum += cur;
        }
        std::cout << "The sum is " << sum << std::endl;
    }
}