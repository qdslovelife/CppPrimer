#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string s;
    std::vector<std::string> vec;
    while(std::cin >> s)
    {
        vec.push_back(s);
    }
    for(auto &item : vec)
    {
        for(auto &ch : item)
        {
            ch = std::toupper(ch);
        }
    }
    for(const auto &item : vec)
    {
        std::cout << item << std::endl;
    }
    return 0;
}