#ifndef _Basket_H
#define _Basket_H

#include <set>
#include <memory>
#include <iostream>
#include "bulk_quote.h"

class Basket
{
public:
    void add_item(const Quote &quote) { items.insert(std::shared_ptr<Quote>(quote.clone())); }
    void add_item(Quote &&quote) { items.insert(std::shared_ptr<Quote>(std::move(quote).clone())); }
    double total_receipt(std::ostream &os) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif