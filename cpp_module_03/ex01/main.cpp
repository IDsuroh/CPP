#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== ClapTrap Tests ===\n";
    {
        ClapTrap c("Clappy");
        c.attack("TargetA");
        c.takeDamage(8);
        c.beRepaired(5);
    }

    std::cout << "\n=== ScavTrap Tests ===\n";
    {
        ScavTrap s("Scavvy");
        s.attack("TargetB");
        s.guardGate();
        s.takeDamage(30);
        s.beRepaired(10);
        
        for (int i = 1; i <= 51; ++i) {
            std::cout << "[Attack " << i << "] ";
            s.attack("TargetC");
        }
    }

    std::cout << "\n=== Polymorphic Deletion Demo ===\n";
    {
        ClapTrap* poly = new ScavTrap("PolyScav");
        poly->attack("TargetX");
        delete poly;
    }

    std::cout << "\nEnd of tests — remaining objects destroyed.\n";
    return 0;
}
