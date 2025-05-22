#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Correct polymorphism ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    std::cout << d->getType() << std::endl;
    std::cout << c->getType() << std::endl;
    c->makeSound();  // Meow~
    d->makeSound();  // Woof!
    meta->makeSound(); // generic
    delete meta;
    delete d;
    delete c;

    std::cout << "\n=== Wrong polymorphism ===" << std::endl;
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    std::cout << wc->getType() << std::endl;
    wc->makeSound(); // still WrongAnimal’s sound, since non-virtual
    wa->makeSound();
    delete wa;
    delete wc;

    std::cout << "\n=== Copy and assignment tests ===" << std::endl;
    Dog dog1;
    Dog dog2 = dog1;
    Dog dog3;
    dog3 = dog1;
    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;

    return 0;
}