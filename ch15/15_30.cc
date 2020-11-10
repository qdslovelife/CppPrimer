#include "basket.h"

int main()
{
    Basket basket;
    basket.add_item(Quote("Harry Potter", 10));
    basket.add_item(Bulk_Quote("XiYouJi", 15, 5, 0.2));
    basket.add_item(Bulk_Quote("ShuiHuZhuan", 15, 10, 0.2));
    basket.total_receipt(std::cout);
    return 0;
}