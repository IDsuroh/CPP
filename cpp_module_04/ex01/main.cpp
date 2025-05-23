#include <iostream>
#include <cassert>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "\t\tTEST 1:\n\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;//should not create a leak
    delete i;
    
    std::cout << "\n\t\tTEST 2:\n\n";
    const int N = 4;
    Animal* zoo[N];

    // ===> NEW: build array of Animals owning Dogs and Cats
    for (int i = 0; i < N; ++i) {
        if (i < N/2)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }

    // tear down
    for (int i = 0; i < N; ++i)
        delete zoo[i];

    std::cout << "\n=== Deep-copy test ===\n";
    Dog original;
    Dog copy = original;

    // <<< NEW: compare brain pointers to prove deep copy
    std::cout << "  \n\toriginal.brain ptr = " << original.getBrain() << "\n";
    std::cout << "      \tcopy.brain ptr = " <<      copy.getBrain() << "\n";
    assert(original.getBrain() != copy.getBrain());
    std::cout << "deep-copy succeeded (distinct Brain pointers)\n";

    return 0;
}