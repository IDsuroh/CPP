#include "HumanA.hpp"
#include <iostream>

// Constructor implementation
HumanA::HumanA(const std::string& name, Weapon& weapon)
    : name(name), weapon(weapon)
{}

// Destructor implementation
HumanA::~HumanA()
{}

// Attack method implementation
void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}