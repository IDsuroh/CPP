#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
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

    std::cout << "\n=== FragTrap Tests ===\n";
    {
        FragTrap f("Fraggy");

        f.attack("TargetF");
        f.highFivesGuys();
        f.takeDamage(50);
        f.beRepaired(25);

        for (int i = 1; i <= 101; ++i) {
            std::cout << "[Attack " << i << "] ";
            f.attack("TargetF2");
        }
    }

    std::cout << "\n=== Destruction Ordering Demo ===\n";
    {
        FragTrap temp("TempFrag");
        temp.takeDamage(200);
    }

    std::cout << "\nEnd of ex02 tests — all done.\n";
    return 0;
}
