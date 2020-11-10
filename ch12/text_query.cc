#include "text_query.h"

using std::vector;
using std::string;
using std::map;
using std::set;
using std::shared_ptr;
using std::ostream;
using std::ifstream;
using std::istringstream;
using std::endl;
using std::getline;

TextQuery::TextQuery(ifstream &is)
    : file_(std::make_shared<std::vector<std::string>>())
{
    string text;
    while(getline(is, text))
    {                
        file_->push_back(text);
        int line_no = file_->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word)
        {
            word.erase(std::remove_if(word.begin(), word.end(), &ispunct), word.end());
            auto &line_nos = word_map_[word];
            if(!line_nos)
            {
                line_nos.reset(new set<size_t>);
            }
            line_nos->insert(line_no);
        }
    }
}

QueryResult TextQuery::query(const string &word) const
{
    static shared_ptr<set<size_t>> nodata(new set<size_t>);
    auto loc = word_map_.find(word);
    if(loc == word_map_.end())
    {
        return QueryResult(word, nodata, file_);
    }
    else
    {
        return QueryResult(word, loc->second, file_);
    }
}

ostream& operator<<(ostream &os, const QueryResult &result)
{
    os << result.word_ << " occurs " << result.lines_->size() << " times" << endl;
    for(auto num : *result.lines_)
    {
        os << "\t(line " << num + 1 << ") " << *(result.file_->begin() + num) << endl;
    }
    return os;
}