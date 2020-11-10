#ifndef _Bulk_Quote_H
#define _Bulk_Quote_H

#include "quote.h"

class Bulk_Quote : public Quote
{
public:
    Bulk_Quote() = default;
    Bulk_Quote(const std::string &bookNo, double price, std::size_t min_qty, double discount)
        : Quote(bookNo, price), min_qty_(min_qty), discount_(discount)
    {}
    virtual double net_price(std::size_t num) const override;
    virtual void debug() const override;
    virtual Bulk_Quote* clone() const & override { return new Bulk_Quote(*this); }
    virtual Bulk_Quote* clone() && override { return new Bulk_Quote(*this); }
private:
    std::size_t min_qty_;
    double discount_ = 0.0;
};

inline double Bulk_Quote::net_price(std::size_t num) const 
{
    if(num > min_qty_)  return (1 - discount_) * num * price_;
    else    return num * price_;
}

inline void Bulk_Quote::debug() const
{
    Quote::debug();
    std::cout << "min_qty: " << min_qty_
              << " discount: " << discount_
              << std::endl;
}

#endif