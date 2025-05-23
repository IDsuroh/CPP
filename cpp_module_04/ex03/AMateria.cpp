#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const & t) : type(t) {
    std::cout << "[AMateria] ctor, type=" << type << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
    std::cout << "[AMateria] copy ctor, type=" << type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "[AMateria] copy assign\n";
    if (this != &other)
        type = other.type;
    return *this;
}

AMateria::~AMateria() {
    std::cout << "[AMateria] dtor, type=" << type << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    // default behavior (can be overridden)
    std::cout << "* uses " << type
              << " on " << target.getName()
              << " *" << std::endl;
}