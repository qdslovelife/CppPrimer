#ifndef _Str_Blob_H
#define _Str_Blob_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>

class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &item);
    StrBlob& operator=(const StrBlob &item);

    size_type size() const { return data_->size(); }
    bool empty() const { return data_->empty(); }

    void push_back(const std::string &s) { data_->push_back(s); }
    void pop_back();

    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
private:
    void check(size_type i, const std::string &msg) const;

    std::shared_ptr<std::vector<std::string>> data_;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr_(0), wptr_() {}
    StrBlobPtr(StrBlob &a, std::size_t sz = 0) : wptr_(a.data_), curr_(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::weak_ptr<std::vector<std::string>> wptr_;
    std::size_t curr_;

    std::shared_ptr<std::vector<std::string>> check(std::size_t curr, const std::string &msg) const;
};

#endif