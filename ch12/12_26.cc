#include <iostream>
#include <string>
#include <memory>

int main()
{
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(10);
    std::string s;
    auto q = p;
    while(std::cin >> s && q != p + 10)
    {
        alloc.construct(q++, s);
    }
    while(q != p)
    {
        alloc.destroy(--q);
    }
    alloc.deallocate(p, 10);
    return 0;
}