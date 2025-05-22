#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] default ctor\n";
    for (int i = 0; i < 100; ++i)
        ideas[i] = "empty";
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] copy ctor\n";
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] copy assign\n";
    if (this != &other)
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] dtor\n";
}
