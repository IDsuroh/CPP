#include "Zombie.hpp"
#include <iostream>

// Default Constructor
Zombie::Zombie()
    : name("Unnamed")
{
    std::cout << "Zombie named => " << name << " created (default)" << std::endl;
}

// Parametrized Constructor
Zombie::Zombie(std::string name)
    : name(name)
{
    std::cout << "Zombie named => " << name << " created (parametrized)" << std::endl;
}

// Copy Constructor
Zombie::Zombie(const Zombie& other)
    : name(other.name)
{
    std::cout << "Zombie named => " << name << " created (copy)" << std::endl;
}

// Copy Assignment Operator
Zombie& Zombie::operator=(const Zombie& other)
{
    if (this != &other) {
        name = other.name;
        std::cout << "Zombie named => " << name << " assigned (copy assignment)" << std::endl;
    }
    return *this;
}

// Destructor
Zombie::~Zombie()
{
    std::cout << "Zombie named => " << name << " destroyed" << std::endl;
}

// Member function to announce the zombie's name
void Zombie::announce(void) const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/*void Zombie::setName(const std::string& newName)
{
    name = newName;
    std::cout << "Zombie named => " << name << " created (default)" << std::endl;
}*/