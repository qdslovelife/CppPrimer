#include <set>
#include <algorithm>
#include "query.h"

Query::Query(const std::string &word)
    : query_(new WordQuery(word))
{}

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs_.eval(text), left = lhs_.eval(text);
    auto ret_lines = std::make_shared<std::set<size_t>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto right = rhs_.eval(text), left = lhs_.eval(text);
    auto ret_lines = std::make_shared<std::set<size_t>>();
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query_.eval(text);
    auto ret_lines = std::make_shared<std::set<size_t>>();
    auto beg = result.begin(), end = result.end();
    auto size = result.get_file()->size();
    for(size_t n = 0; n != size; ++n)
    {
        if(beg == end || *beg != n)
        {
            ret_lines->insert(n);
        }
        else if(beg != end)
        {
            ++beg;
        }
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}