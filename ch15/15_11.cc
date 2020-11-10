#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"

void print_debug(const Quote &quote)
{
    quote.debug();
}

int main()
{
    Quote quote("Harry Potter", 10);
    Bulk_Quote bulk_quote("XiYouJi", 15, 5, 0.2);
    Limit_Quote limit_quote("ShuiHuZhuan", 15, 10, 0.2);
    print_debug(quote);
    print_debug(bulk_quote);
    print_debug(limit_quote);
    return 0;
}