#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;

    std::cout << "b = " << b << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    // Arithmetic examples
    Fixed x(3.5f);
    Fixed y(1.25f);
    std::cout << "\nArithmetic operations with x=3.5 and y=1.25:" << std::endl;
    std::cout << "x + y = " << x + y << std::endl;
    std::cout << "x - y = " << x - y << std::endl;
    std::cout << "x * y = " << x * y << std::endl;
    std::cout << "x / y = " << x / y << std::endl;

    // Comparison examples
    std::cout << "\nComparison operations:" << std::endl;
    std::cout << std::boolalpha;
    std::cout << "x > y: "  << (x > y)  << std::endl;
    std::cout << "x < y: "  << (x < y)  << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    // Increment/decrement examples
    Fixed inc;
    std::cout << "\nIncrement/Decrement operations starting from inc=" << inc << std::endl;
    std::cout << "++inc: " << ++inc << std::endl;
    std::cout << "inc++: " << inc++ << std::endl;
    std::cout << "after inc++: " << inc << std::endl;
    std::cout << "--inc: " << --inc << std::endl;
    std::cout << "inc--: " << inc-- << std::endl;
    std::cout << "after inc--: " << inc << std::endl;

    // Min/Max examples
    std::cout << "\nMin/Max helpers with x and y:" << std::endl;
    std::cout << "min(x, y): " << Fixed::min(x, y) << std::endl;
    std::cout << "max(x, y): " << Fixed::max(x, y) << std::endl;

    return 0;
}