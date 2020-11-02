#include "person.h"

std::istream& read(std::istream& is, Person &item)
{
    is >> item.name_ >> item.address_;
    return is;
}

std::ostream& print(std::ostream& os, const Person &item)
{
    os << item.name_ << " " << item.address_;
    return os;
}