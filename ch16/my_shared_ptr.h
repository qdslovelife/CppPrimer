#ifndef _Shared_Ptr_H
#define _Shared_Ptr_H

#include <algorithm>

template <typename _Ty>
class Shared_Ptr;

template <typename _Ty>
inline void swap(Shared_Ptr<_Ty> &lhs, Shared_Ptr<_Ty> &rhs)
{
    using std::swap;
    swap(lhs.ptr_, rhs.ptr_);
    swap(lhs.count_, rhs.count_);
    swap(lhs.del_, rhs.del_);
}

template <typename _Ty>
class Shared_Ptr
{
    using DelFuncPtr = void (*)(_Ty*);
    friend void swap<_Ty>(Shared_Ptr<_Ty> &, Shared_Ptr<_Ty> &);
public:
    Shared_Ptr(_Ty *ptr = nullptr, DelFuncPtr del = nullptr)
        : ptr_(ptr), count_(new std::size_t(ptr != nullptr)), del_(del)
    {}
    Shared_Ptr(const Shared_Ptr &sp)
        : ptr_(sp.ptr_), count_(sp.count_), del_(sp.del_)
    {
        ++*count_;
    }
    Shared_Ptr(Shared_Ptr &&sp) noexcept
        : ptr_(sp.ptr_), count_(sp.count_), del_(sp.del_)
    {}
    Shared_Ptr& operator=(Shared_Ptr sp)
    {
        swap(*this, sp);
        return *this;
    }
    Shared_Ptr& operator=(Shared_Ptr &&sp)  noexcept
    {
        swap(*this, sp);
        return *this;
    }
    ~Shared_Ptr()
    {
        if(--*count_ == 0)
        {
            del_ ? del_(ptr_) : delete ptr_;
            delete count_;
        }
        ptr_ = nullptr;
        count_ = nullptr;
    }

    _Ty* get() const { return ptr_; }
    _Ty& operator*() const { return *ptr_; }
    _Ty* operator->() const { return ptr_; }
    size_t use_count() const { return *count_; }
    operator bool() const { return ptr_ != nullptr; }
private:
    _Ty *ptr_ = nullptr;
    std::size_t *count_ = nullptr;
    DelFuncPtr del_ = nullptr;
};

#endif