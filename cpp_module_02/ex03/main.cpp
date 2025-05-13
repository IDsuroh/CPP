#include <iostream>
#include "Point.hpp"

extern bool bsp(Point const, Point const, Point const, Point const);

int main() {
    Point   A(0, 0), B(5, 0), C(0, 5);
    Point   P1(1, 1);   // inside
    Point   P2(5, 5);   // outside
    Point   P3(0, 0);   // vertex
    Point   P4(2.5f, 0);// on edge

    std::cout << std::boolalpha;
    std::cout << "P1 inside: " << bsp(A, B, C, P1) << "\n";
    std::cout << "P2 inside: " << bsp(A, B, C, P2) << "\n";
    std::cout << "P3 inside: " << bsp(A, B, C, P3) << "\n";
    std::cout << "P4 inside: " << bsp(A, B, C, P4) << "\n";

    return 0;
}