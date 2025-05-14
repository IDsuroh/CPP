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
/* void* raw = ::operator new[](sizeof(Zombie) * N);
 :: the allocation function that gives you a contiguous block of memory big enough for N Zombies,
 but it does not run any constructors.
 new (&horde[i]) Zombie(name); => construct a Zombie in the memory at address &horde[i]


Zombie* zombieHorde(int N, std::string name)    {
    if (N <= 0)
        return NULL;
    Zombie* horde = new Zombie[N];  // single allocation of N Zombies
    for (int i = 0; i < N; i++) {   // initialize each zombie’s name
        horde[i].setName(name);      // invokes Zombie(std::string) to create a temp, then operator=
    }
    return horde;
}
 Allocate a single array of N Zombies (calls the default ctor N times),
 then assign each one the desired name via the copy-assignment operator.

In C++, allocation and construction are two distinct steps:

    Allocation is handled by the operator new (and operator new[]) functions.

        These are just ordinary functions (you can even override them) whose job is
	to carve out a chunk of memory—much like malloc() in C.

        They know nothing about your class’s constructors or members; they simply
	return a void* pointing to raw, uninitialized storage.

    Construction is handled by the language’s new‐expression or by placement new.

        A normal new Zombie[N] expression is conceptually equivalent to:

            Call ::operator new[](sizeof(Zombie)*N)

            Loop over each slot and invoke the constructor via placement new

            Return the typed pointer

        By calling ::operator new[] yourself, you stop at step 1.
	No constructors are run automatically.

        You then explicitly invoke each constructor with

new (&horde[i]) Zombie(name);

which is exactly the placement‐new syntax that tells the compiler,
“construct a Zombie at this memory address.”


 */