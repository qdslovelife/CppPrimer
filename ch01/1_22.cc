#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total_trans, cur_trans;
    if(std::cin >> total_trans)
    {
        while(std::cin >> cur_trans)
        {
            if(total_trans.isbn() == cur_trans.isbn())
            {
                total_trans += cur_trans;
            }
            else
            {
                std::cout << "The total is " << total_trans << std::endl;
                std::cout << "You can continue inputing trans: " << std::endl;
                total_trans = cur_trans;
            }
        }
        std::cout << "The total is " << total_trans << std::endl;
    }
    else
    {
        std::cout << "Please input correct trans." << std::endl;
    }
    return 0;
}