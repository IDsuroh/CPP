#include "Brain.hpp"

Brain::Brain() {
    std::cout << "[Brain] Brain has been formed\n";
    for (int i = 0; i < 100; ++i)
        ideas[i] = "empty";
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] Brain has been copied and formed\n";
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] Brain has been switched\n";
    if (this != &other)
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] Brain has been melted\n";
}
