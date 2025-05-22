#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name)
    :   ClapTrap(name + " => GOING TO INHERIT MULTIPLY"),
        ScavTrap(name + " => GOING TO INHERIT MULTIPLY"),
        FragTrap(name + " => GOING TO INHERIT MULTIPLY")   {
    _name = name;

    _hitPoints      =   FragTrap::_hitPoints;
    _energyPoints   =   ScavTrap::_energyPoints;
    _attackDamage   =   FragTrap::_attackDamage;

    std::cout
            << "DiamondTrap's name is " << _name
            << "\nI am constructed with HP(Inherited from Frag) = "
            << _hitPoints
            << "\nEP(Inherited from Scav) = " << _energyPoints
            << "\nAD(Inherited from Frag) = " << _attackDamage << "\n";
}

DiamondTrap::~DiamondTrap() {
    std::cout
        << "DiamondTrap " << _name
        << " destroyed.\n";
}

void    DiamondTrap::whoAmI()   {
    std::cout
        << "My DiamondTrap name is " << _name
        << " and the ClapTrap name is " << ClapTrap::_name
        << ".\n";
}