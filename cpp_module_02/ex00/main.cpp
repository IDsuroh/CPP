#include "Fixed.hpp"
#include <iostream>

/*int main(void)  {
    Fixed   a;
    Fixed   b(a);
    Fixed   c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}*/

#include <iostream>
#include "Fixed.hpp"

int main() {
    // 1) Default construction
    Fixed a;
    std::cout << "a (default)    : " << a.getRawBits() << "\n\n";

    // 2) setRawBits()
    a.setRawBits(42);
    std::cout << "a after setRawBits(42): " << a.getRawBits() << "\n\n";

    // 3) Copy construction
    Fixed b(a);
    std::cout << "b (copy constructed from a): " << b.getRawBits() << "\n\n";

    // 4) Copy assignment
    Fixed c;
    c = a;
    std::cout << "c (assigned from a)       : " << c.getRawBits() << "\n\n";

    // 5) Chained assignment
    Fixed d, e;
    d.setRawBits(100);
    e.setRawBits(200);
    std::cout << "before chaining: d=" << d.getRawBits()
              << ", e=" << e.getRawBits() << "\n";

    e = a;  // first assign a into e
    d = e;  // then assign e into d
    std::cout << "after chaining : d=" << d.getRawBits()
              << ", e=" << e.getRawBits() << "\n";

    return 0;
}