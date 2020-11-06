#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> creat()
{
    return std::make_shared<std::vector<int>>();
}

void input(std::shared_ptr<std::vector<int>> s_ptr)
{
    int i;
    while(std::cin >> i)
    {
        s_ptr->push_back(i);
    }
    return ;
}

void output(const std::shared_ptr<std::vector<int>> s_ptr)
{
    for(auto item : *s_ptr)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return ;
}

int main()
{
    auto s_ptr = creat();
    input(s_ptr);
    output(s_ptr);
    return 0;
}