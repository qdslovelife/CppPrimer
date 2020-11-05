#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> vec;
    std::string word;
    while(std::cin >> word)
    {
        if(std::find(vec.begin(), vec.end(), word) == vec.end())
        {
            vec.push_back(word);
        }
    }
    for(const auto &w : vec)
    {
        std::cout << w << " ";
    }
    std::cout << std::endl;
    return 0;
}