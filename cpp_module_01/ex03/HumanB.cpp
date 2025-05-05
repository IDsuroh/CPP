#include "HumanB.hpp"
#include <iostream>

// Constructor implementation
HumanB::HumanB(const std::string& name)
    : name(name), weapon(NULL)
{}

// Destructor implementation
HumanB::~HumanB()
{}

// Set weapon method implementation
void HumanB::setWeapon(Weapon& w) {
    weapon = &w;
}

// Attack method implementation
void HumanB::attack() const {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}