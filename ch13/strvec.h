#ifndef _Str_Vec_H
#define _Str_Vec_H

#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

class StrVec
{
public:
    StrVec()
        : element_(nullptr), first_free_(nullptr), cap_(nullptr)
    {}
    StrVec(std::initializer_list<std::string> il);
    StrVec(const StrVec &strvec);
    StrVec& operator=(const StrVec &strvec);
    StrVec(StrVec &&strvec);
    StrVec& operator=(StrVec &&strvec);
    ~StrVec();
    void push_back(const std::string &str);
    size_t size() const { return first_free_ - element_; }
    size_t capacity() const { return cap_ - element_; }
    std::string* begin() const { return element_; }
    std::string* end() const { return first_free_; }
private:
    static std::allocator<std::string> alloc;

    void chk_n_alloc() { if(size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();
    void reallocate();
    std::string *element_;
    std::string *first_free_;
    std::string *cap_;
};

#endif