#include <algorithm>
#include "strvec.h"

void StrVec::push_back(const std::string &str)
{
    chk_n_alloc();
    alloc.construct(first_free_++, str);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *beg, const std::string *end)
{
    auto new_begin = alloc.allocate(end - beg);
    return {new_begin, std::uninitialized_copy(beg, end, new_begin)};
}

void StrVec::free()
{
    if(element_)
    {
        for(auto p = first_free_; p != element_;)
        {
            alloc.destroy(--p);
        }
        // std::for_each(element_, first_free_, [this](std::string &str){ alloc.destroy(&str); });
        alloc.deallocate(element_, cap_ - element_);
    }
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
    auto new_begin = alloc_n_copy(il.begin(), il.end());
    element_ = new_begin.first;
    first_free_ = cap_ = new_begin.second;
}

StrVec::StrVec(const StrVec &strvec)
{
    auto new_begin = alloc_n_copy(strvec.begin(), strvec.end());
    element_ = new_begin.first;
    first_free_ = new_begin.second;
}

StrVec& StrVec::operator=(const StrVec &strvec)
{
    auto new_begin = alloc_n_copy(strvec.begin(), strvec.end());
    free();
    element_ = new_begin.first;
    first_free_ = cap_ = new_begin.second;
    return *this;
}

StrVec::StrVec(StrVec &&strvec)
    : element_(strvec.element_), first_free_(strvec.first_free_), cap_(strvec.cap_)
{
    strvec.element_ = strvec.first_free_ = strvec.cap_ = nullptr;
}

StrVec& StrVec::operator=(StrVec &&strvec)
{
    if(this != &strvec)
    {
        free();
        element_ = strvec.element_;
        first_free_ = strvec.first_free_;
        cap_ = strvec.cap_;
        strvec.element_ = strvec.first_free_ = strvec.cap_ = nullptr;
    }
    return *this;
}

void StrVec::reallocate()
{
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_begin = alloc.allocate(new_capacity);
    auto dest = new_begin;
    auto element = element_;
    for(size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++, std::move(*element++));
    }
    free();
    element_ = new_begin;
    first_free_ = dest;
    cap_ = new_begin + new_capacity;
}