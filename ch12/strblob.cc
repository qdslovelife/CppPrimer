#include "strblob.h"

using std::vector;
using std::string;
using std::initializer_list;
using std::out_of_range;
using std::runtime_error;
using std::shared_ptr;
using std::size_t;
using std::make_shared;

StrBlob::StrBlob()
    : data_(make_shared<vector<string>>())
{}

StrBlob::StrBlob(initializer_list<string> il)
    : data_(make_shared<vector<string>>(il))
{}

StrBlob::StrBlob(const StrBlob &item)
    : data_(make_shared<vector<string>>(*item.data_))
{}

StrBlob& StrBlob::operator=(const StrBlob &item)
{
    if(this == &item)   return *this;
    data_.~shared_ptr();
    data_ = make_shared<vector<string>>(*item.data_);
    return *this;
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data_->pop_back();
}

string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data_->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data_->back();
}

const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data_->front();
}

const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data_->back();
}

void StrBlob::check(size_type i, const string &msg) const
{
    if(i >= data_->size())
    {
        throw out_of_range(msg); 
    }
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data_->size());
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr_, "dereference past end");
    return (*p)[curr_];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr_, "increment past end of StrBlobPtr");
    ++curr_;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr_.lock();
    if(!ret)    
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret->size())
    {
        throw out_of_range(msg);
    }
    return ret;
}