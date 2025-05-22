#include "Animal.hpp"
#include <iostream>

Animal::Animal()
    :   type("UNKNOWN")
{
    std::cout
        << "[Animal] DEFAULT CONSTRUCTOR called, type = "
        << type
        << std::endl;
}

Animal::Animal(const Animal& other)
    :   type(other.type)
{
    std::cout
        << "[Animal] COPY CONSTRUCTOR called, type = "
        << type
        << std::endl;
}

Animal  Animal::operator=(const Animal& other)  {
    std::cout
        << "[Animal] COPY ASSIGNMENT called"
        << std::endl;
    if (this != other)
        type = other.type;
    return *this;
}

Animal::~Animal()   {
    std::cout
        << "[Animal] DESTRUCTOR called, type = "
        << type
        << std::endl;
}

void    Animal::makeSound() const   {
    std::cout
        << "[Animal] All Kinds of ANIMAL SOUNDS"
        << std::endl;
}

std::string Animal::getType() const   {
    return type;
}