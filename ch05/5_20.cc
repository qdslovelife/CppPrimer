#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;
    int flag = 0;
    if(std::cin >> s1)
    {
        while(std::cin >> s2)
        {
            if(s1 == s2)
            {
                std::cout << "The repear string is " << s1 << std::endl;
                flag = 1;
                break;
            }
            else
            {
                s1 = s2;
            }
        }
    }
    if(!flag)
    {
        std::cout << "There is no repeat string." << std::endl;
    }
    return 0;
}