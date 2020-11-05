#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cctype>
#include <algorithm>

int main()
{
    std::map<std::string, size_t> word_count;
    std::set<std::string> black_list = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    std::string word;
    while(std::cin >> word)
    {
        if(black_list.find(word) == black_list.end())
        {
            word.erase(std::remove_if(word.begin(), word.end(), [](char &ch){ return std::ispunct(ch);}), 
                                      word.end());
            for(auto &ch : word)
            {
                if(std::isupper(ch))
                {
                    ch = std::tolower(ch);
                }
            }
            ++word_count[word];
        }
    }
    for(const auto &word : word_count)
    {
        std::cout << word.first << " occurs " << word.second << ((word.second > 1) ? " times" : " time") << std::endl;
    }
    return 0;
}