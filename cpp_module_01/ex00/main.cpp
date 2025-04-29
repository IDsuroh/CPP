#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie*    newZombie(std::string name);
void       randomChump(std::string name);

int main()
{
    std::cout << "=== Stack-allocated Zombies ===" << std::endl;
    // Default constructor
    Zombie z1;
    z1.announce();

    // Parametrized constructor
    Zombie z2("Parameter Constructed Zombozo");
    z2.announce();

    // Copy constructor
    Zombie z3(z2); 
    z3.announce();  //Could also write Zombie z3 = z2;
    
    // Copy assignment operator
    Zombie z4;
    z4 = z2;
    z4.announce();

    // Heap‐allocated zombie:
    std::cout << std::endl << "=== Heap-allocated Zombies ===" << std::endl;
    Zombie* heapZombie = newZombie("Heap-allocated Zombozibo");
    heapZombie->announce();
    delete heapZombie;

    // Stack‐allocated zombie:
    std::cout << std::endl << "=== Stack-allocated Zombies ===" << std::endl;
    randomChump("Stack-allocated Zombizibozo");

    // Destructor will be called automatically for stack-allocated zombies
    std::cout << std::endl << "=== Destructor called ===" << std::endl;
    return 0;
}