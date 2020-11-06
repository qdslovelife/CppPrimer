#include <iostream>
#include <vector>

std::vector<int>* creat()
{
    return new std::vector<int>();
}

void input(std::vector<int> *ptr)
{
    int i;
    while(std::cin >> i)
    {
        ptr->push_back(i);
    }
    return ;
}

void output(const std::vector<int> *ptr)
{
    for(auto item : *ptr)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return ;
}

int main()
{
    auto ptr = creat();
    input(ptr);
    output(ptr);
    delete ptr;
    return 0;
}