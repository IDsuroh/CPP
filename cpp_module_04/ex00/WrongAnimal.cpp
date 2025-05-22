#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Karen") {
    std::cout << "[WrongAnimal] DEFAULT CONSTRUCTOR, type = " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
    std::cout << "[WrongAnimal] COPY CONSTRUCTOR" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "[WrongAnimal] COPY ASSIGNMENT" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "[WrongAnimal] DESTRUCTOR, type = " << type << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "[WrongAnimal] yapping about something stupid" << std::endl;
}

std::string WrongAnimal::getType() const {
    return type;
}