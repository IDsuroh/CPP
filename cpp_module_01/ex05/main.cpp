#include "Harl.hpp"
#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./harl <LEVEL>" << std::endl;
        return 1;
    }
    for (char *str = argv[1]; *str; ++str)  {
        *str = static_cast<char>(std::toupper(static_cast<unsigned char>(*str)));
    }
    Harl    harl;
    harl.complain(argv[1]);
    return 0;
}