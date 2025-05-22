#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    type = "Dog";
    std::cout << "[Dog] DEFAULT CONSTRUCTOR called, type = " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "[Dog] COPY CONSTRUCTOR called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] COPY ASSIGNMENT called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] DESTRUCTOR called, type = " << type << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}