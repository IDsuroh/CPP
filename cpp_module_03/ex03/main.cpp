#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== DiamondTrap Demo ===\n";
    {
        DiamondTrap d("Diamond");
        d.attack("The Enemy");
        d.highFivesGuys();
        d.guardGate();
        d.whoAmI();
    }
    std::cout << "\nEnd of ex03 demo.\n";
    return 0;
}
