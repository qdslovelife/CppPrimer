#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec1 = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> vec2 = {1,2,3,4,5};
    const std::vector<int> *ptr1 = nullptr;
    const std::vector<int> *ptr2 = nullptr;

    if(vec1.size() < vec2.size())
    {
        ptr1 = &vec1;
        ptr2 = &vec2;
    }
    else
    {
        ptr1 = &vec2;
        ptr2 = &vec1;
    }
    for(int i = 0; i < ptr1->size(); ++i)
    {
        if((*ptr1)[i] != (*ptr2)[i])
        {
            std::cout << "False." << std::endl;
            return 0;
        }
    }
    std::cout << "True." << std::endl;
    return 0;
}