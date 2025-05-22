#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\t\t=== Correct polymorphism ===\n" << std::endl;
    const Animal* random = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << "\t" << d->getType() << " Barks like ";
    d->makeSound();

    std::cout << "\t" << c->getType() << " Meows like ";
    c->makeSound();

    std::cout << "\t" << random->getType() << " makes ";
    random->makeSound();

    delete random;
    delete d;
    delete c;

    std::cout << "\n\n\t\t=== Wrong polymorphism ===\n" << std::endl;
    const WrongAnimal* karen = new WrongAnimal();
    const WrongAnimal* fakecat = new WrongCat();

    std::cout << "\t" << fakecat->getType() << "should make fakecat sound ->\n\tMeahahahahahaw but it is \n\t";
    fakecat->makeSound();

    std::cout << "\tThe wrong animal karen is \n\t";
    karen->makeSound();

    std::cout << "\n\tWhen virtual is not set,\n\tpolymorphism doesn't work and fake cat malfunctions...\n\n";
    
    delete fakecat;
    delete karen;

    std::cout << "\n\n\t\t=== Copy and assignment tests ===\n" << std::endl;
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