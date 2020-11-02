#ifndef _Sales_Data_H
#define _Sales_Data_H
#include <string>
#include <iostream>

class SalesData;

std::istream& read(std::istream &is, SalesData &item);
std::ostream& print(std::ostream &os, const SalesData &item);
SalesData add(const SalesData &lhs, const SalesData &rhs);

class SalesData
{
    friend std::istream& read(std::istream &is, SalesData &item);
    friend std::ostream& print(std::ostream &os, const SalesData &item);
    friend SalesData add(const SalesData &lhs, const SalesData &rhs);
public:
    SalesData() = default;
    SalesData(const std::string &bookNo) : bookNo_(bookNo) {}
    SalesData(const std::string &bookNo, unsigned units_sold, double price)
        : bookNo_(bookNo), units_sold_(units_sold), revenue_(units_sold * price) {}
    SalesData(std::istream &is)
        : SalesData()
    { read(std::cin, *this); }
    std::string isbn() const {return bookNo_; }
    SalesData& combine(const SalesData&);
    double avg_price() const;
private:
    std::string bookNo_;
    unsigned units_sold_ = 0;
    double revenue_ = 0.0;
};

inline double SalesData::avg_price() const
{
    if(units_sold_)
    {
        return revenue_ / units_sold_;
    }
    else
    {
        return 0;
    }
}

#endif