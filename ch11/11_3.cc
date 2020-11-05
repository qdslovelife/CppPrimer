#include <iostream>
#include <string>
#include <map>
#include <set>

int main()
{
    std::map<std::string, size_t> word_count;
    std::set<std::string> black_list = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    std::string word;
    while(std::cin >> word)
    {
        if(black_list.find(word) == black_list.end())
        {
            ++word_count[word];
        }
    }
    for(const auto &word : word_count)
    {
        std::cout << word.first << " occurs " << word.second << ((word.second > 1) ? " times" : " time") << std::endl;
    }
    return 0;
}