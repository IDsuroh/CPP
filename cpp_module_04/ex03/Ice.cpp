#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
    std::cout << "[Ice] ctor\n";
}

Ice::Ice(const Ice& other) : AMateria(other) {
    std::cout << "[Ice] copy ctor\n";
}

Ice& Ice::operator=(const Ice& other) {
    std::cout << "[Ice] copy assign\n";
    (void)other;
    return *this;
}

Ice::~Ice() {
    std::cout << "[Ice] dtor\n";
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at "
              << target.getName()
              << " *" << std::endl;
}