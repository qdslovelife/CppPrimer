#include "basket.h"

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;
    for(auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        sum += (*iter)->net_price(items.count(*iter));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}