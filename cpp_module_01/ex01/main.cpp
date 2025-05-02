#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <sstream>

static int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int value = 0;
    if (!(ss >> value) || !ss.eof()) {
        std::cerr << "Invalid number: " << str << std::endl;
        return -1;  // Return an error value
    }
    return value;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <number_of_zombies>" << " <name_of_the_zombies>" << std::endl;
        return 1;
    }
    const int N = stringToInt(argv[1]);
    if (N <= 0) {
        std::cerr << "Error: Number of zombies must be a positive integer." << std::endl;
        return 1;
    }
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;
    Zombie* horde = zombieHorde(N, argv[2]);
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    std::cout << "Deleting the horde..." << std::endl;
    for (int i = 0; i < N; ++i) {   // 3) Manually call each destructor:
        horde[i].~Zombie();
    }
    ::operator delete[](horde);     // 4) Deallocate the raw memory:
    std::cout << "Horde deleted." << std::endl;
    return 0;
}

/*int main(int argc, char **argv)
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <number_of_zombies>" << " <name_of_the_zombies>" << std::endl;
        return 1;
    }
    const int N = stringToInt(argv[1]);
    if (N <= 0) {
        std::cerr << "Error: Number of zombies must be a positive integer." << std::endl;
        return 1;
    }
    std::cout << "Creating a horde of " << N << " zombies..." << std::endl;
    Zombie* horde = zombieHorde(N, argv[2]);
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    std::cout << "Deleting the horde..." << std::endl;
    delete[] horde;  // Deallocate the array of zombies
    std::cout << "Horde deleted." << std::endl;
    return 0;
}*/