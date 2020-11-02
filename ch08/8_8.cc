#include <fstream>
#include <string>
#include <vector>
#include "../ch07/sales_data.h"

int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2], std::ofstream::app | std::ofstream::out);
    SalesData total;
    if(read(input, total))
    {
        SalesData trans;
        while(read(input, trans))
        {
            if(total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(output, total) << std::endl;
                total = trans;
            }
        }
        print(output, total) << std::endl;
    }
    else
    {
        std::cerr << "No data?!" << std::endl;
    }
    return 0;
}