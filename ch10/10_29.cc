#include <iostream>
#include <vector>
#include <iterator>
#include <string>

int main()
{
    std::istream_iterator<std::string> item_iter(std::cin), eof;
    std::ostream_iterator<std::string> os_iter(std::cout, "\n");
    std::vector<std::string> vec;
    while(item_iter != eof)
    {
        vec.push_back(*item_iter++);
    }
    for(const auto &s : vec)
    {
        os_iter = s;
    }
    return 0;
}