#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <sstream>

class QueryResult;

std::ostream& print(std::ostream& os, const QueryResult& result);

class TextQuery
{
public:
    TextQuery(std::ifstream& is);
    QueryResult query(const std::string &word) const;
private:
    std::map<std::string, std::shared_ptr<std::set<size_t>>> word_map_;
    std::shared_ptr<std::vector<std::string>> file_;
};

class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(const std::string &word, const std::shared_ptr<std::set<size_t>> lines, const std::shared_ptr<std::vector<std::string>> file)
        : word_(word), lines_(lines), file_(file)
    {}
    std::set<size_t>::iterator begin() const { return lines_->begin(); }
    std::set<size_t>::iterator end() const { return lines_->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() const { return file_; }
private:
    std::string word_;
    std::shared_ptr<std::set<size_t>> lines_;
    std::shared_ptr<std::vector<std::string>> file_;
};