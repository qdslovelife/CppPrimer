#include <iostream>
#include <vector>
#include <string>

int main()
{
    const std::vector<std::string> scores = {"F", "E", "D", "C", "B", "A", "A++"};
    int grade;
    std::string lettergrade;

    while(std::cin >> grade)
    {
        lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];
        lettergrade += (grade > 7) ? "+" 
                                   : (grade < 3) ? "-" : "";
        std::cout << "Lettergrade is " << lettergrade << std::endl;
    }
}