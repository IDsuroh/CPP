#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
      _hitPoints(10),
      _energyPoints(10),
      _attackDamage(0)
{
    std::cout
        << "ClapTrap " << _name
        << " constructed! [HP=" << _hitPoints
        << ", EP=" << _energyPoints
        << ", AD=" << _attackDamage
        << "]\n";
}

ClapTrap::~ClapTrap()
{
    std::cout
        << "ClapTrap " << _name
        << " has been destroyed.\n";
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0) {
        std::cout
            << "ClapTrap " << _name
            << " has no hit points and cannot attack.\n";
        return ;
    }
    if (_energyPoints == 0) {
        std::cout
            << "ClapTrap " << _name
            << " has no energy and cannot attack.\n";
        return ;
    }

    --_energyPoints;
    std::cout
        << "ClapTrap " << _name
        << " attacks " << target
        << ", causing " << _attackDamage
        << " points of damage! [EP left=" << _energyPoints << "]\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0) {
        std::cout
            << "ClapTrap " << _name
            << " is already at 0 HP.\n";
        return;
    }

    if (amount >= _hitPoints) {
        _hitPoints = 0;
        std::cout
            << "ClapTrap " << _name
            << " takes " << amount
            << " points of damage and has died!\n";  // ← fixed message
    }
    else {
        _hitPoints -= amount;
        std::cout
            << "ClapTrap " << _name
            << " takes " << amount
            << " points of damage, HP=" << _hitPoints
            << "\n";
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints == 0) {
        std::cout
            << "ClapTrap " << _name
            << " is dead and cannot be repaired.\n";
        return;
    }
    if (_energyPoints == 0) {
        std::cout
            << "ClapTrap " << _name
            << " has no energy and cannot repair itself.\n";
        return;
    }

    --_energyPoints;
    _hitPoints += amount;

    std::cout
        << "ClapTrap " << _name
        << " is repaired by " << amount
        << " points! [HP=" << _hitPoints
        << ", EP=" << _energyPoints << "]\n";
}