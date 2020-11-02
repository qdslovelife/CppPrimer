#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);
    std::string cur_str;
    std::vector<std::string> vec;
    while(std::getline(input, cur_str))
    {
        vec.push_back(cur_str);
    }
    return 0;
}