#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
    :   _rawBits(0)
{}

Fixed::Fixed(const Fixed& other)    {
    *this = other;
}

Fixed&  Fixed::operator=(const Fixed& other)    {
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{}

int Fixed::getRawBits(void) const   {
    return _rawBits;
}

void    Fixed::setRawBits(int const raw)    {
    _rawBits = raw;
}

Fixed::Fixed(int const i)   {
    _rawBits = i << _fbits;
}

Fixed::Fixed(float const f) {
    _rawBits = roundf(f * (1 << _fbits));
}

float Fixed::toFloat(void)  const   {
    return static_cast<float>(_rawBits) / (1 << _fbits);
}

int Fixed::toInt(void)  const   {
    return _rawBits >> _fbits;
}

bool Fixed::operator>(Fixed const& r) const  {
    return _rawBits > r._rawBits;
}

bool Fixed::operator<(Fixed const& r) const  {
    return _rawBits < r._rawBits;
}

bool Fixed::operator>=(Fixed const& r) const  {
    return _rawBits >= r._rawBits;
}

bool Fixed::operator<=(Fixed const& r) const  {
    return _rawBits <= r._rawBits;
}

bool Fixed::operator==(Fixed const& r) const  {
    return _rawBits == r._rawBits;
}

bool Fixed::operator!=(Fixed const& r) const  {
    return _rawBits != r._rawBits;
}

Fixed   Fixed::operator+(Fixed const& r) const  {
    Fixed   tmp;
    tmp._rawBits = _rawBits + r._rawBits;
    return tmp;
}

Fixed   Fixed::operator-(Fixed const& r) const  {
    Fixed   tmp;
    tmp._rawBits = _rawBits - r._rawBits;
    return tmp;
}

Fixed   Fixed::operator*(Fixed const& r) const  {
    Fixed   tmp;
    tmp._rawBits = (int)(((long long)_rawBits * r._rawBits) >> _fbits);
    return tmp;
}

Fixed   Fixed::operator/(Fixed const& r) const  {
    Fixed   tmp;
    tmp._rawBits = (int)((((long long)_rawBits) << _fbits) / r._rawBits);
    return tmp;
}

Fixed&   Fixed::operator++()    {
    ++_rawBits;
    return *this;
}

Fixed&  Fixed::operator--() {
    --_rawBits;
    return *this;
}

Fixed   Fixed::operator++(int)  {
    Fixed   old(*this);
    ++_rawBits;
    return old;
}

Fixed   Fixed::operator--(int)  {
    Fixed   old(*this);
    --_rawBits;
    return old;
}

Fixed&  Fixed::min(Fixed& a, Fixed& b)  {
    return (a < b ? a : b);
}

Fixed&  Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a: b);
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b) {
    return (a < b ? a : b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
    return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& os, Fixed const& fx) {
    os << fx.toFloat();
    return os;
}