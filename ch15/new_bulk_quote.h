#ifndef _New_Bulk_Quote_H
#define _New_Bulk_Quote_H

#include "disc_quote.h"

class Bulk_Quote : public Disc_Quote
{
public:
    Bulk_Quote() = default;
    Bulk_Quote(const std::string &bookNo, size_t price, size_t quantity, double discount)   
        : Disc_Quote(bookNo, price, quantity, discount)
    {}
    virtual double net_price(size_t num) const override;
};

double Bulk_Quote::net_price(size_t num) const
{
    if(num > quantity_) return (1 - discount_) * num * price_;
    else
    {
        return num * price_;
    }
}

#endif