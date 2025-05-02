#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}
// Allocates a new Zombie on the heap, returns a pointer.
// Caller is responsible for delete‐ing it.