#ifndef _Limit_Quote_H
#define _Limit_Quote_H

#include "quote.h"

class Limit_Quote : public Quote
{
public:
    Limit_Quote() = default;
    Limit_Quote(const std::string &bookNo, size_t price, size_t max_pty, double discount)
        : Quote(bookNo, price), max_pty_(max_pty), discount_(discount)
    {}
    virtual double net_price(size_t num) const override;
    virtual void debug() const override;
private:
    size_t max_pty_;
    double discount_;
};

inline double Limit_Quote::net_price(size_t num) const
{
    if(num <= max_pty_)  return (1 - discount_) * num * price_;
    else
    {
        return (1 - discount_) * max_pty_ * price_ + (num - max_pty_) * price_;
    }
}

inline void Limit_Quote::debug() const
{
    Quote::debug();
    std::cout << "max_pty: " << max_pty_
              << " discount: " << discount_
              << std::endl;
}

#endif