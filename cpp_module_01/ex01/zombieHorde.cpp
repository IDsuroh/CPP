#include "Zombie.hpp"
#include <new>

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;
    void* raw = ::operator new[](sizeof(Zombie) * N);   // 1) Raw allocation of N * sizeof(Zombie) bytes:
    Zombie* horde = static_cast<Zombie*>(raw);
    for (int i = 0; i < N; ++i) {                       // 2) In-place construction of each Zombie with the parameterized ctor:
        new (&horde[i]) Zombie(name);   // calls Zombie(std::string) directly;
    }
    return horde;
}
// void* raw = ::operator new[](sizeof(Zombie) * N);
// :: is the C++ scope‐resolution operator to force lookup in the global namespace.
// placement‐new expression
// new (&horde[i]) Zombie(name); => construct a Zombie in the memory at address &horde[i]

/*
Zombie* zombieHorde(int N, std::string name)    {
    if (N <= 0)
        return NULL;
    Zombie* horde = new Zombie[N];  // single allocation of N Zombies
    for (int i = 0; i < N; i++) {   // initialize each zombie’s name
        horde[i].setName(name);      // invokes Zombie(std::string) to create a temp, then operator=
    }
    return horde;
}*/
// Allocate a single array of N Zombies (calls the default ctor N times),
// then assign each one the desired name via the copy-assignment operator.