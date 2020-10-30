#include <iostream>

int main()
{
    int sum = 0, val = 50;
    while(val <= 100)
    {
        sum += val;
        ++val;
    }

    sum = 0;
    for(val = 50; val <= 100; ++val)
    {
        sum += val;
    }
    return 0;
}