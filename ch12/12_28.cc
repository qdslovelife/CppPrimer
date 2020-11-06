#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <sstream>

void input_file(std::vector<std::string> &texts, std::map<std::string, std::set<size_t>> &word_map, const char* file)
{
    std::string text;
    std::ifstream is(file);
    while(std::getline(is, text))
    {
        texts.push_back(text);
        int line_no = texts.size() - 1;
        std::istringstream line(text);
        std::string word;
        while(line >> word)
        {
            auto &line_nos = word_map[word];
            line_nos.insert(line_no);
        }
    }
}

std::ostream& print(std::ostream &os, const std::string &word, const std::vector<std::string> &texts, const std::set<size_t> &lines)
{
    os << word << " occurs " << lines.size() << " times" << std::endl;
    for(auto num : lines)
    {
        os << "\t(line " << num + 1 << ") " << texts[num] << std::endl;
    }
    return os;
}

void query(const std::string &word, const std::vector<std::string> &texts, const std::map<std::string, std::set<size_t>> &word_map)
{
    auto loc = word_map.find(word);
    if(loc == word_map.end())
    {
        std::cout << "There is no word" << std::endl;
    }
    else
    {
        print(std::cout, word, texts, loc->second);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "a.exe file" << std::endl;
        return 1;
    }

    std::vector<std::string> file;
    std::map<std::string, std::set<size_t>> word_map;
    input_file(file, word_map, argv[1]);
    while(true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if(!(std::cin >> s) || s == "q")    break;
        query(s, file, word_map);
    }
    return 0;
}