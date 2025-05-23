#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
    std::cout << "[Cure] ctor\n";
}

Cure::Cure(const Cure& other) : AMateria(other) {
    std::cout << "[Cure] copy ctor\n";
}

Cure& Cure::operator=(const Cure& other) {
    std::cout << "[Cure] copy assign\n";
    (void)other;
    return *this;
}

Cure::~Cure() {
    std::cout << "[Cure] dtor\n";
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals "
              << target.getName()
              << "'s wounds *" << std::endl;
}