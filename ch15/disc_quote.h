#ifndef _Disc_Quote_H
#define _Disc_Quote_H

#include "quote.h"

class Disc_Quote : public Quote
{
public:
    Disc_Quote() = default;
    Disc_Quote(const std::string &bookNo, size_t price, size_t quantity, double discount)
        : Quote(bookNo, price), quantity_(quantity), discount_(discount)
    {}
    virtual double net_price(size_t num) const = 0;
protected:
    size_t quantity_ = 0;
    double discount_ = 0.0;
};

#endif