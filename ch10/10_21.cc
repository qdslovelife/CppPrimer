#include <iostream>

void func(int count)
{
    auto f = [count] () mutable -> bool { if(count-- > 0)   return true; else return false; };
    while(1)
    {
        auto bool_ = f();
        std::cout << bool_ << std::endl;
        if(!bool_)  return;
    }
}

int main()
{
    func(5);
    return 0;
}