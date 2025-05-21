// ex01/ScavTrap.cpp
#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string& name)
  : ClapTrap(name)
{
    _hitPoints   = 100;
    _energyPoints= 50;
    _attackDamage= 20;
    std::cout
        << "ScavTrap " << _name
        << " constructed! [HP=" << _hitPoints
        << ", EP=" << _energyPoints
        << ", AD=" << _attackDamage << "]\n";
}

ScavTrap::~ScavTrap()
{
    std::cout
        << "ScavTrap " << _name
        << " destroyed.\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0) {
        std::cout << "ScavTrap " << _name
                  << " has no HP and cannot attack.\n";
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "ScavTrap " << _name
                  << " has no EP and cannot attack.\n";
        return;
    }
    --_energyPoints;
    std::cout
        << "ScavTrap " << _name
        << " fiercely attacks " << target
        << ", dealing " << _attackDamage
        << " damage! [EP left=" << _energyPoints << "]\n";
}

void ScavTrap::guardGate()
{
    std::cout
        << "ScavTrap " << _name
        << " is now in Gate keeper mode.\n";
}
