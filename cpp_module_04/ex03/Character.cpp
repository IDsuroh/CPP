#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & n) : name(n) {
    std::cout << "[Character] ctor, name=" << name << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "[Character] copy ctor\n";
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "[Character] copy assign\n";
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "[Character] dtor, name=" << name << std::endl;
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    // inventory full → drop it
    delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) return;
    inventory[idx] = 0;  // do not delete!
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4) return;
    if (inventory[idx])
        inventory[idx]->use(target);
}