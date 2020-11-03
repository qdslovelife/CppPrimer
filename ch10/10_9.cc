#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void elimDups(std::vector<std::string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    std::cout << "ElimDups: " << std::endl;
    for(const auto &word : words)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    words.erase(end_unique, words.end());
}

int main()
{
    std::vector<std::string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    std::cout << "Before: " << std::endl;
    for(const auto &word : vec)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    elimDups(vec);
    std::cout << "After: " << std::endl;
    for(const auto &word : vec)
    {
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}