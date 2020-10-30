#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item prev_trans, cur_trans;
    int count = 0;
    if(std::cin >> prev_trans)
    {
        count = 1;
        while(std::cin >> cur_trans)
        {
            if(prev_trans.isbn() == cur_trans.isbn())
            {
                ++count;
            }
            else
            {
                std::cout << "ISBN: " << prev_trans.isbn() << " occurs " << count << " times." << std::endl;
                prev_trans = cur_trans;
                count = 1;
            }
        }
        std::cout << "ISBN: " << prev_trans.isbn() << " occurs " << count << " times." << std::endl;
    }
    else
    {
        std::cout << "Please input correct trans." << std::endl;
    }
    return 0;
}