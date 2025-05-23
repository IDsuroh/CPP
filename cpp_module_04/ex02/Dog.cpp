#include "Dog.hpp"
#include <iostream>

Dog::Dog()
    :   brain(new Brain())
{
    type = "Dog";
    std::cout << "[Dog] DEFAULT CONSTRUCTOR called, type = " << type << std::endl;
}

Dog::Dog(const Dog& other)
    :   Animal(other),
        brain(new Brain(*other.brain))
{
    std::cout << "[Dog] COPY CONSTRUCTOR called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] COPY ASSIGNMENT called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "[Dog] DESTRUCTOR called, type = " << type << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return brain;
}