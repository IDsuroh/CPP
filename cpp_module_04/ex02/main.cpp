#include <iostream>
#include <cassert>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "\t\tTEST 1: simple Dog/Cat\n\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    j->makeSound();
    i->makeSound();
    
    delete j; // must call Dog::~Dog -> Animal::~Animal
    delete i; // must call Cat::~Cat -> Animal::~Animal
    
    // -----------------------------------------------------------------------
    std::cout << "\n\t\tTEST 2: array of Animals\n\n";
    const int N = 4;
    Animal* zoo[N];

    for (int idx = 0; idx < N; ++idx) {
        if (idx < N/2) zoo[idx] = new Dog();
        else           zoo[idx] = new Cat();
    }
    for (int idx = 0; idx < N; ++idx)
        delete zoo[idx];
    
    // -----------------------------------------------------------------------
    std::cout << "\n\t\tTEST 3: deep-copy Dog\n\n";
    Dog original;
    Dog copy = original;  // deep-copy via copy constructor

    std::cout << "  \n\toriginal.brain ptr = " << original.getBrain() << "\n"
              << "      \tcopy.brain ptr = " <<      copy.getBrain() << "\n";
    assert(original.getBrain() != copy.getBrain());
    std::cout << "\ndeep-copy succeeded (distinct Brain pointers)\n";

    // -----------------------------------------------------------------------
    std::cout << "\n\t\tTEST 4: abstract class enforcement\n\n";
    // Uncommenting any of the following lines should produce a compile-time error:
    //
    //   Animal a;               // error: cannot instantiate abstract class
    //   Animal* pa = new Animal(); // same error
    //
    // All concrete subclasses (Dog, Cat) remain instantiable:
    Dog* d = new Dog();
    Cat* c = new Cat();
    d->makeSound();
    c->makeSound();
    delete d;
    delete c;

    std::cout << "\nAll tests passed.\n";
    return 0;
}
