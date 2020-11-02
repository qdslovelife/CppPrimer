#include <iostream>

void swap(int *lhs, int *rhs)
{
    int temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}

int main()
{
    int a = 1, b = 2;
    swap(&a, &b);
    std::cout << "a: " << a << "\t" << "b: " << b << std::endl;
    return 0;
}