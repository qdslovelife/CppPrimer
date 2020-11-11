#ifndef _Debug_Delete_H
#define _Debug_Delete_H

#include <iostream>

class Debug_Delete
{
    Debug_Delete(std::ostream &os = std::cout)
        : os_(os)
    {}
    template <typename _Ty>
    void operator()(_Ty *ptr)   
    {
        os << "deleting unique_ptr" << std::endl;
        delete ptr;
    }
private:
    std::ostream &os_;
};

#endif