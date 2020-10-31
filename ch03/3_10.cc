#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;
    for(auto &ch : s)
    {
        if(!std::ispunct(ch))
        {
            std::cout << ch;
        }
    }
    return 0;
}