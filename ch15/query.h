#ifndef _Query_H
#define _Query_H

#include <memory>
#include "query_base.h"

Query operator~(const Query &);
Query operator|(const Query &, const Query &);
Query operator&(const Query &, const Query &);
std::ostream& operator<<(std::ostream &, const Query &);

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const std::string &);
    Query(std::shared_ptr<Query_Base> query)
        : query_(query)
    {}
    QueryResult eval(const TextQuery &t) const { return query_->eval(t); }
    std::string rep() const { return query_->rep(); }
private:

    std::shared_ptr<Query_Base> query_;
};

class BinaryQuery : public Query_Base
{
protected:
    BinaryQuery(const Query &lhs, const Query &rhs, const std::string &opSym)
        : lhs_(lhs), rhs_(rhs), opSym_(opSym)
    {}
    std::string rep() const override { return "( " + lhs_.rep() + " " + opSym_ + " " + rhs_.rep() + " )"; }
    Query lhs_, rhs_;
    std::string opSym_;
};

class WordQuery : public Query_Base
{
    friend class Query;
    WordQuery(const std::string &query_word)
        : query_word_(query_word)
    {}
    QueryResult eval(const TextQuery &t) const override { return t.query(query_word_); }
    std::string rep() const override { return query_word_; }
    std::string query_word_;
};

class NotQuery : public Query_Base
{
    friend Query operator~(const Query &);
    NotQuery(const Query &query)
        : query_(query)
    {}
    std::string rep() const override { return "~( " + query_.rep() + " )"; }
    QueryResult eval(const TextQuery &) const override;
    Query query_;
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &lhs, const Query &rhs)
        : BinaryQuery(lhs, rhs, "&")
    {}
    QueryResult eval(const TextQuery &) const override;
};

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &lhs, const Query &rhs)
        : BinaryQuery(lhs, rhs, "|")
    {}
    QueryResult eval(const TextQuery &) const override;
};

inline Query operator~(const Query &query)
{
    return std::shared_ptr<Query_Base>(new NotQuery(query));
}

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_Base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_Base>(new OrQuery(lhs, rhs));
}

inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

#endif