#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool bigger(const std::string &s1)
{
    return s1.size() >= 5;
}

bool isShorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main()
{
    std::vector<std::string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);
    std::stable_sort(vec.begin(), vec.end(), isShorter);  
    auto end = std::partition(vec.begin(), vec.end(), bigger);
    auto begin = vec.begin();
    while(begin != end)
    {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;
    return 0;
}