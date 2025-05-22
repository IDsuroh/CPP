#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap	{
private:
    std::string _name;
public:
	DiamondTrap(const std::string& name);
    ~DiamondTrap();

    using ScavTrap::attack;

    void    whoAmI();
};


#endif