#include "Cat.hpp"
#include <iostream>

Cat::Cat()
    :   brain(new Brain())
{
    type = "Cat";
    std::cout << "[Cat] DEFAULT CONSTRUCTOR called, type = " << type << std::endl;
}

Cat::Cat(const Cat& other)
    :   Animal(other),
        brain(new Brain(*other.brain))
{
    std::cout << "[Cat] COPY CONSTRUCTOR called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] COPY ASSIGNMENT called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "[Cat] DESTRUCTOR called, type = " << type << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow~" << std::endl;
}

Brain* Cat::getBrain() const {
    return brain;
}