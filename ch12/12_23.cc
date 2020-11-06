#include <iostream>
#include <cstring>

int main()
{
    char *p1 = "hello,";
    char *p2 = " world";
    size_t p1_size = strlen(p1);
    size_t p2_size = strlen(p2);
    auto p3 = new char[p1_size + p2_size]();
    auto start = p3;

    for(int i = 0; i < p1_size; ++i)
    {
        *p3 = *p1;
        ++p3;
        ++p1;
    }
    for(int i = 0; i < p2_size; ++i)
    {
        *p3 = *p2;
        ++p3;
        ++p2;
    }
    *p3 = '\0';
    std::cout << start << std::endl;
    return 0;
}