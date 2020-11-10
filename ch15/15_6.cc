#include <iostream>
#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"

double print_total(std::ostream &os, const Quote &quote, size_t num)
{
    double total_price = quote.net_price(num);
    os << "ISBN: " << quote.isbn() << " # sold: " << num << " total price: " << total_price << std::endl;
    return total_price;
}

int main()
{
    Quote quote("Harry Potter", 10);
    Bulk_Quote bulk_quote("XiYouJi", 15, 5, 0.2);
    Limit_Quote limit_quote("ShuiHuZhuan", 15, 10, 0.2);
    Disc_Quote disc_quote();
    print_total(std::cout, quote, 10);
    print_total(std::cout, bulk_quote, 10);
    print_total(std::cout, limit_quote, 15);
    return 0;
}