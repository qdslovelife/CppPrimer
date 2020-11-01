#include <iostream>

int main()
{
    int vowel_count = 0;
    char ch;

    while(std::cin >> ch)
    {
        if(ch == 'a' || ch == 'A')   ++vowel_count;
        if(ch == 'e' || ch == 'E')   ++vowel_count;
        if(ch == 'i' || ch == 'I')   ++vowel_count;
        if(ch == 'o' || ch == 'O')   ++vowel_count;
        if(ch == 'u' || ch == 'U')   ++vowel_count;
    }
    std::cout << "The amount of vowel is " << vowel_count << std::endl;
}