#ifndef _Person_H
#define _Person_H

#include <string>
#include <iostream>

std::istream& read(std::istream &is, Person &item);
std::ostream& print(std::ostream &os, const Person &item);

class Person
{
    friend std::istream& read(std::istream &is, Person &item);
    friend std::ostream& print(std::ostream &os, const Person &item);
public:
    Person() = default;
    Person(std::string name, std::string address) : name_(name), address_(address) {}
    Person(std::istream &is)
        : Person()
    { read(std::cin, *this); }
    std::string get_name() const { return name_; }
    std::string get_address() const { return address_; }
private:
    std::string name_;
    std::string address_;
};

#endif