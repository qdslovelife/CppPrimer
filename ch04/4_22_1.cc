#include <iostream>
#include <string>

int main()
{
    int grade;
    std::string finalgrade;

    std::cin >> grade;
    finalgrade = (grade > 90) ? "high pass"
                              : (grade < 60) ? "fail"
                                             : (grade < 75) ? "low pass" : "pass";
    std::cout << finalgrade << std::endl;
    return 0;
}