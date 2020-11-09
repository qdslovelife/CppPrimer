#include "employee.h"

int Employee::ID = 0;

Employee::Employee(const Employee &item)
    : name_(item.name_), id_(ID++)
{}

Employee& Employee::operator=(const Employee &item)
{
    name_ = item.name_;
    id_ = ID++;
    return *this;
}