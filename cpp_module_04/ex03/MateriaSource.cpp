#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    std::cout << "[MateriaSource] ctor\n";
    for (int i = 0; i < 4; ++i)
        learned[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "[MateriaSource] copy ctor\n";
    for (int i = 0; i < 4; ++i)
        learned[i] = other.learned[i]
                     ? other.learned[i]->clone()
                     : 0;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "[MateriaSource] copy assign\n";
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete learned[i];
            learned[i] = other.learned[i]
                         ? other.learned[i]->clone()
                         : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << "[MateriaSource] dtor\n";
    for (int i = 0; i < 4; ++i)
        delete learned[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!learned[i]) {
            learned[i] = m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (learned[i] && learned[i]->getType() == type)
            return learned[i]->clone();
    }
    return 0;
}