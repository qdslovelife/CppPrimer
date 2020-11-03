#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::deque<std::string> d;
    std::string word;
    std::deque<std::string>::const_iterator iter;
    while(std::cin >> word)
    {
        d.push_back(word);
    }
    iter = d.cbegin();
    while(iter != d.cend())
    {
        std::cout << *iter << std::endl;
        ++iter;
    }
    return 0;
}