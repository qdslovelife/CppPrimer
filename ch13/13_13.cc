#include <iostream>

struct X
{
    X() { std::cout << "X()" << std::endl; }
    X(const X &) { std::cout << "X(const X &)" << std::endl; }
    X& operator=(const X &) { std::cout << "operatpr=(const X &)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

X func(X x1)
{
    return x1;
}

int main()
{
    X x1;
    func(x1);
    return 0;
}