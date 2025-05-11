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
    _rawBits = raw;
}

Fixed::Fixed(int const i)   {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = i << _fbits;
}

Fixed::Fixed(float const f) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fbits));
}

float Fixed::toFloat(void)  const   {
    return static_cast<float>(_rawBits) / (1 << _fbits);
}

int Fixed::toInt(void)  const   {
    return _rawBits >> _fbits;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fx) {
    os << fx.toFloat();
    return os;
}