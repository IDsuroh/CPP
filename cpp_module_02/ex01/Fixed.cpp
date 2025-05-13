#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
    :   _rawBits(0) {
        std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)    {
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = other._rawBits;
}

Fixed&  Fixed::operator=(const Fixed& other)    {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const   {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void    Fixed::setRawBits(int const raw)    {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

Fixed::Fixed(int const i)   {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = i << _fbits; // i << _fbits == i * (2^_fbits) ***
}

Fixed::Fixed(float const f) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fbits)); //  f * (1 << 8) is f * 256.0f ***
}

float Fixed::toFloat(void)  const   {
    return static_cast<float>(_rawBits) / (1 << _fbits);
}

int Fixed::toInt(void)  const   {
    return _rawBits >> _fbits;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fx) { //stream‐insertion operator overload
    os << fx.toFloat();
    return os;
}

/*

Fixed::Fixed(int const i)   {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = i << _fbits; // i << _fbits == i * (2^_fbits) ***
}

Example with 10
Decimal 10 in binary is "0000 0000 0000 1010"

Shift it left 8 positions:

0000 0000 0000 1010 << 8  →  0000 1010 0000 0000
0000 1010 0000 0000₂ = 10 × (2^8) = 10 × 256 = 2560

So when writing in your constructor:
_rawBits = i << _fbits;  // where _fbits == 8
it is converting the integer i into fixed-point form by multiplying it by 256 under the hood. (Since _fbits are set to int 8)
Later on, it can divided by 256 (or shift right by 8) to recover the integer part, or divide to get back a float.


*****************************************************************************************************************************


Fixed::Fixed(float const f) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fbits));
}

Example with 42.42f

float f = 42.42f;

Scale by 2⁸:

float scaled = f * (1 << _fbits); f * (1 << 8) is f * 256.0f; 42.42f * 256
    → scaled ≈ 42.42f * 256 = 10859.52f

Round to nearest integer:

int raw = roundf(scaled);
    → raw = roundf(10859.52f) = 10860

Store in _rawBits:

_rawBits = raw; _rawBits == 10860

Binary view:

Decimal 10860 in binary is:

10860₁₀ = 00101010 01110100₂
└─ high bits 00101010₂ = 42
└─ low bits 01110100₂ ≈ 0.421875

Recovering later:

float back = static_cast<float>(_rawBits) / (1 << _fbits);
    → back = 10860.0f / 256 = 42.421875f
(very close to the original 42.42f)


*****************************************************************************************************************************


float Fixed::toFloat(void)  const   {
    return static_cast<float>(_rawBits) / (1 << _fbits);
}

Example with a Fixed constructed from 42.42f:

Fixed const c(42.42f);

During construction:

_rawBits = roundf(42.42f * 256);
         = roundf(10859.52f);
         = 10860;            // stored internally

Call toFloat():

float Fixed::toFloat() const {
    return static_cast<float>(_rawBits) / (1 << _fbits);
}
Plug in the numbers

return 10860.0f / 256.0f;
// → 42.421875f

Usage in code:

std::cout << c.toFloat() << std::endl;
// prints: 42.4219


*****************************************************************************************************************************


int Fixed::toInt(void)  const   {
    return _rawBits >> _fbits;
}
Fixed const b(10);

// In the int constructor:
_rawBits = 10 << 8;  // 10 * 256 = 2560

int result = b.toInt();  
// which does: 2560 >> 8  (i.e. 2560 / 256, discarding remainder)
// → result = 10

std::cout << b.toInt() << std::endl;  // prints: 10


*****************************************************************************************************************************


std::ostream& operator<<(std::ostream& os, Fixed const& fx) { //stream‐insertion operator overload
    os << fx.toFloat();
    return os;
}
    overloading =   providing an additional function that the compiler can pick when the left operand
                    is an ostream and the right operand is the Fixed type
Without this overload, writing:

Fixed a(10);
std::cout << a;
would be a compile-error, because std::ostream has no built-in way to handle the custom type.

With this function:
'std::cout << a;' is equivalent to 'std::cout << a.toFloat();' under the hood.

*/