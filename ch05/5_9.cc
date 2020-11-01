#include <iostream>

int main()
{
    int vowel_count = 0;
    char ch;

    while(std::cin >> ch)
    {
        if(ch == 'a')   ++vowel_count;
        if(ch == 'e')   ++vowel_count;
        if(ch == 'i')   ++vowel_count;
        if(ch == 'o')   ++vowel_count;
        if(ch == 'u')   ++vowel_count;
    }
    std::cout << "The amount of vowel is " << vowel_count << std::endl;
}