#include <iostream>
#include <vector>

int add(int val1, int val2)
{
    return val1 + val2;
}

int sub(int val1, int val2)
{
    return val1 - val2;
}

int mul(int val1, int val2)
{
    return val1 * val2;
}
int div(int val1, int val2)
{
    return val1 / val2;
}

int main()
{
    std::vector<int(*)(int, int)> vec;
    vec.push_back(add);
    vec.push_back(sub);
    vec.push_back(mul);
    vec.push_back(div);
    std::cout << vec[0](1, 2) << std::endl;
    std::cout << vec[1](2, 2) << std::endl;
    std::cout << vec[2](2, 4) << std::endl;
    std::cout << vec[3](4, 2) << std::endl;
    return 0; 
}