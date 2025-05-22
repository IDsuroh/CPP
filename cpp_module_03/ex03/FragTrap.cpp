#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name)
  : ClapTrap(name)
{
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout
        << "FragTrap " << _name
        << " constructed! [HP=" << _hitPoints
        << ", EP=" << _energyPoints
        << ", AD=" << _attackDamage << "]\n";
}

FragTrap::~FragTrap()
{
    std::cout
        << "FragTrap " << _name
        << " destroyed.\n";
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name
                  << " has no HP and cannot attack.\n";
        return;
    }
    if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name
                  << " has no EP and cannot attack.\n";
        return;
    }
    --_energyPoints;
    std::cout
        << "FragTrap " << _name
        << " launches a heavy attack on " << target
        << ", causing " << _attackDamage
        << " damage! [EP left=" << _energyPoints << "]\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout
        << "FragTrap " << _name
        << " requests a high five! ✋\n";
}