#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    :   _name(name),
        _hitPoints(10),
        _energyPoints(10),
        _attackDamage(0)    {
    std::cout
        << "ClapTrap " << _name
        << " constructed! [HP=" << _hitPoints
        << ", EP=" << _energyPoints
        << ", AD=" << _attackDamage
        << std::endl;
}

ClapTrap::~ClapTrap()   {
    std::cout
        << "ClapTrap " << _name
        << " has no hit points and cannot attack."
        << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (_hitPoints == 0)    {
        std::cout << "ClapTrap " << _name
        << " has no hit points and cannot attack."
        << std::endl;
    }
    if (_energyPoints == 0) {
        std::cout
            << "ClapTrap " << _name
            << " has no energy and cannot attack."
            << std::endl;
    }
    --_energyPoints;
    std::cout
        << "ClapTrap " << _name
        << " attacks " << target
        << ", causing " << _attackDamage
        << " points of damage! [Ep left=" << _energyPoints << "]"
        << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)   {
    if (_hitPoints == 0)    {
        std::cout
            << "ClapTrap " << _name
            << " is already at 0 HP."
            << std::endl;
        return ;
    }
    if (amount >= _hitPoints)   {
        _hitPoints = 0;
        std::cout
            << "ClapTrap " << _name
            << " takes " << amount
            << " points of damage and is not dead!"
            << std::endl;
    } else {
        _hitPoints -= amount;
        std::cout
            << "ClapTrap " << _name
            << " takes " << amount
            << " points of damage, HP=" << _hitPoints
            << std::endl;
    }
}