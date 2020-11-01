#include <iostream>
#include <stdexcept>

int main()
{
    int val1, val2;
    while(std::cin >> val1 >> val2)
    {
        try
        {
            if(val2 == 0)
            {
                throw std::overflow_error("divisor can't be 0.");
            }
            std::cout << val1 / val2 << std::endl;
        }
        catch(const std::overflow_error& e)
        {
            std::cout << e.what() << std::endl;
            std::cout << "Please retry." << std::endl;
        }
    }
    return 0; 
}