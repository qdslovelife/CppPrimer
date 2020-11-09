#ifndef _Employee_H
#define _Employee_H

#include <iostream>
#include <string>

class Employee
{
public:
    Employee() : name_(), id_(ID++) {}
    Employee(std::string name) : name_(name), id_(ID++) {}
    Employee(const Employee &item);
    Employee& operator=(const Employee &item);
private:
    static int ID;
    std::string name_;
    int id_;
};

#endif