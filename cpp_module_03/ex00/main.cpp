#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Normal construction & attack ===\n";
    ClapTrap ct1("CT1");
    ct1.attack("Enemy1");

    std::cout << "\n=== Test 2: Energy depletion ===\n";
    ClapTrap ct2("CT2");
    for (int i = 1; i <= 11; ++i) {
        std::cout << "[Attack " << i << "] ";
        ct2.attack("Enemy2");
    }

    std::cout << "\n=== Test 3: Taking damage (partial & lethal) ===\n";
    ClapTrap ct3("CT3");
    ct3.takeDamage(5);
    ct3.takeDamage(10);

    std::cout << "\n=== Test 4: Repair functionality ===\n";
    ClapTrap ct4("CT4");
    ct4.takeDamage(3);
    ct4.beRepaired(2);
    for (int i = 1; i <= 11; ++i) {
        std::cout << "[Repair " << i << "] ";
        ct4.beRepaired(1);
    }

    std::cout << "\n=== Test 5: Actions when HP == 0 ===\n";
    ct3.attack("Ghost");
    ct3.takeDamage(3);

    std::cout << "\n=== Test 6: Destructor messages ===\n";
    {
        ClapTrap temp("Temp");
        temp.takeDamage(20);
    }

    std::cout << "\nEnd of main — remaining objects will be destroyed now.\n";
    return 0;
}
