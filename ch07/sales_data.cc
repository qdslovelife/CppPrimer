#include "sales_data.h"

SalesData& SalesData::combine(const SalesData &item)
{
    units_sold_ += item.units_sold_;
    revenue_ += item.revenue_;
    return *this;
}

std::istream& read(std::istream &is, SalesData &item)
{
    double price = 0;
    is >> item.bookNo_ >> item.units_sold_ >> price;
    item.revenue_ = price * item.units_sold_;
    return is;
}

std::ostream& print(std::ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.units_sold_ << " " << item.revenue_ << " " << item.avg_price();
    return os;
}

SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}