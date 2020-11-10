#include <memory>
#include <vector>
#include "quote.h"
#include "bulk_quote.h"

int main()
{
    std::vector<std::shared_ptr<Quote>> basket;
    basket.push_back(std::make_shared<Quote>("Harry Potter", 10));
    basket.push_back(std::make_shared<Bulk_Quote>("XiYouJi", 15, 5, 0.2));
    basket.push_back(std::make_shared<Bulk_Quote>("ShuiHuZhuan", 15, 10, 0.2));
    double total_price = 0.0;
    for(const auto ptr : basket)
    {
        total_price += ptr->net_price(10);
    }
    std::cout << total_price << std::endl;
    return 0;
}