#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}
// Creates a Zombie on the stack, announces it, then it
// is automatically destroyed when this function returns.