#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);
    std::vector<std::string> vec;
    std::string s;
    while(std::getline(input, s))
    {
        vec.push_back(s);
    }
    for(auto &str : vec)
    {
        std::istringstream iss(str);
        iss >> s;
        std::cout << s << std::endl;
    }
    return 0;
}