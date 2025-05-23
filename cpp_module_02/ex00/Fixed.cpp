#include "Fixed.hpp"
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

/*
const Fixed& other says “I want a reference to an existing Fixed object, and I won’t modify it.”
*/