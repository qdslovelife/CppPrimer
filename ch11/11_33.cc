#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <stdexcept>

using std::runtime_error;
using std::string;
using std::ifstream;
using std::map;
using std::istringstream;
using std::getline;

map<string, string> build_map(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while(map_file >> key && getline(map_file, value))
    {
        if(value.size() > 1)
        {
            trans_map[key] = value.substr(1);
        }
        else
        {
            throw runtime_error("no rule for " + key);
        }
    }
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &trans_map)
{
    auto iter = trans_map.find(s);
    if(iter != trans_map.end())
    {
        return iter->second;
    }
    else
    {
        return s;
    }
}

void word_transform(ifstream &map_file, ifstream &input_file)
{
    auto trans_map = build_map(map_file);
    string text;
    while(getline(input_file, text))
    {
        istringstream is(text);
        string word;
        bool first_word = true;
        while(is >> word)
        {
            if(first_word)  first_word = false;  
            else    std::cout << " ";
        }
        std::cout << transform(word, trans_map);
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cerr << "a.exe file1 file2" << std::endl;
        return 1;
    }
    ifstream map_if(argv[1]);
    ifstream input_if(argv[2]);
    word_transform(map_if, input_if);
    return 0;
}