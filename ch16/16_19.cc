#include <iostream>
#include <vector>

template <typename _Ty>
void print(_Ty &container)
{
    using size_type = typename _Ty::size_type;
    size_type length = container.size();
    for(size_type i = 0; i < length; ++i)
    {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,0};
    print(vec);
    return 0;
}