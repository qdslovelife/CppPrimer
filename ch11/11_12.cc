#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main()
{
    std::string s;
    int i;
    std::vector<std::pair<std::string, int>> vec;
    while(std::cin >> s >> i)
    {
        vec.push_back(std::make_pair(s, i));
      //vec.push_back({s, i});
      //vec.emplace_back(s, i);  
    }
    return 0;
}