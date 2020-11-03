#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

bool check_size(const std::string &s, std::string::size_type sz)
{
    return s.size() >= sz;
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

void biggies(std::vector<std::string> &words, std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);
    auto wc = std::partition(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));
    std::for_each(words.begin(), wc, [](const std::string &s) { std::cout << s << std::endl; });
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    int i = 0;
    std::cin >> i;
    biggies(vec, i);
    return 0;    
}