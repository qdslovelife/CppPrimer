#ifndef _New_Limit_Quote_H
#define _New_Limit_Quote_H

#include "disc_quote.h"

class Limit_Quote : public Disc_Quote
{
public:
    Limit_Quote() = default;
    Limit_Quote(const std::string &bookNo, size_t price, size_t quantity, double discount)
        : Disc_Quote(bookNo, price, quantity, discount)
    {}
    virtual double net_price(size_t num) const override;
};

double Limit_Quote::net_price(size_t num) const
{
    if(num < quantity_) return (1 - discount_) * num * price_;
    else
    {
        return quantity_ * (1 - discount_) * price_ + (num - quantity_) * price_;
    }
}

#endif