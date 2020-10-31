#include <iostream>
#include <string>

int main()
{
    int grade;
    std::string finalgrade;

    std::cin >> grade;
    if(grade > 90)
    {
        finalgrade = "high pass";
    }
    else if(grade > 75)
    {
        finalgrade = "pass";
    }
    else if(grade > 60)
    {
        finalgrade = "low pass";
    }
    else
    {
        finalgrade = "fail";
    }
    std::cout << finalgrade << std::endl;
    return 0;
}