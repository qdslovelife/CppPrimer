#ifndef _Quote_H
#define _Quote_H

#include <iostream>
#include <string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &bookNo, double price)
        : bookNo_(bookNo), price_(price)
    {}
    std::string isbn() const { return bookNo_; }
    virtual double net_price(std::size_t num) const { return num * price_; }
    virtual void debug() const;
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(*this); }
    virtual ~Quote() = default;
protected:
    double price_ = 0.0;
private:
    std::string bookNo_;
};

inline void Quote::debug() const
{
    std::cout << "price: " << price_
              << " bookNo: " << bookNo_
              << std::endl;
}

#endif