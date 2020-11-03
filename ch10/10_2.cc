#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::vector<std::string> vec  ={"ni", "hap", "ni", "dhd"};
    std::string s = "ni";
    std::cout << std::count(vec.cbegin(), vec.cend(), s) << std::endl;
    return 0;
}