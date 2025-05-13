#include "Fixed.hpp"
#include <iostream>

struct NoStream {
    int x;
};

int main(void)  {
    std::cout << "\n";
/*——— Case 1: our overload is in play ———*/
    Fixed   a;
    Fixed   const b(10);
    Fixed   const c(42.42f);
    Fixed   const d(b);
    a = Fixed(1234.4321f);

    std::cout << "\n";
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

/*——— Case 2: no overload available ———*/
#ifdef SHOW_NOSTREAM
    NoStream ns{42};
    std::cout << "NoStream ns: " << ns << std::endl;
#endif

    std::cout
        << "\nTO CHECK COMPILATION ERROR, COMMENT LINE 27 AND 30\n"
        << "\n\tOR MANUALLY COMPILE WITH\n"
        << "\n\tg++ -std=c++98 -DSHOW_NOSTREAM main.cpp -o test\n"
        << "\n\tOR ADD #define SHOW_NOSTREAM\n\n";

    return 0;
}

/*
the single line a = Fixed(1234.4321f); produces:

Create a temporary Fixed object from the float literal:

Fixed::Fixed(float const f) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fbits));
}    
    ->  Float constructor called


Call your copy‐assignment operator to assign tmp into a:

Fixed& Fixed::operator=(Fixed const& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other.getRawBits();
    return *this;
}
    ->  Copy assignment operator called


Destroy the temporary tmp at the end of the full expression.
   
    Destructor called

Putting that all together, it produces:

Float constructor called
Copy assignment operator called
Destructor called

*/