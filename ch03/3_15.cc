#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::vector<std::string> vec;
    while(std::cin >> s)
    {
        vec.push_back(s);
    }
    return 0;
}