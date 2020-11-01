#include <iostream>

int main()
{
    int vowel_count = 0, white_count = 0, tab_count = 0, line_count = 0;
    char ch;

    while(std::cin >> ch)
    {
        if(ch == 'a' || ch == 'A')   ++vowel_count;
        if(ch == 'e' || ch == 'E')   ++vowel_count;
        if(ch == 'i' || ch == 'I')   ++vowel_count;
        if(ch == 'o' || ch == 'O')   ++vowel_count;
        if(ch == 'u' || ch == 'U')   ++vowel_count;
        if(ch == ' ')   ++white_count;
        if(ch == '\t')  ++tab_count;
        if(ch == '\n')  ++line_count;
    }
    std::cout << "The amount of vowel is " << vowel_count << std::endl;
    std::cout << "The amount of white is " << white_count << std::endl;
    std::cout << "The amount of tab is " << tab_count << std::endl;
    std::cout << "The amount of line is " << line_count << std::endl;
}