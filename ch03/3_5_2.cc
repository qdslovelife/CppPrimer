#include <iostream>
#include <string>

int main()
{
    std::string total_str, cur_str;
    if(std::cin >> total_str)
    {
        while(std::cin >> cur_str)
        {
            total_str = total_str + " " + cur_str;
        }
        std::cout << total_str << std::endl;
    }
    return 0;
}