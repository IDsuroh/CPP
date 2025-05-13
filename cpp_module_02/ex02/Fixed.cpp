#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
    :   _rawBits(0)
{}

Fixed::Fixed(const Fixed& other)    {
    this->_rawBits = other._rawBits;
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

/*****/

Fixed   Fixed::operator*(Fixed const& r) const  {
    Fixed       tmp;
    long long   prod = (long long)_rawBits * r._rawBits;
    tmp._rawBits = (int)(prod >> _fbits);
    return tmp;
}

Fixed   Fixed::operator/(Fixed const& r) const  {
    Fixed       tmp;
    long long   num = ((long long)_rawBits) << _fbits;
    tmp._rawBits = (int)(num / r._rawBits);
    return tmp;
}

/*****/

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

/**Fixed::operator*** step-by-step:

Grab the raw fixed-point values
   int rawA = this->_rawBits;  // “a” scaled by 2⁸
   int rawB = r._rawBits;      // “b” scaled by 2⁸
long long prod = (long long)rawA * rawB;
// prod == (a·2⁸) × (b·2⁸) == (a·b)·2¹⁶
prod >>= _fbits;              // same as prod /= 256
// now prod == (a·b)·2⁸, the correct fixed-point encoding
tmp._rawBits = (int)prod;
// store the 64→32-bit narrowed result in tmp._rawBits
return tmp;
// tmp now represents the fixed-point encoding of 4.375


int rawA = this->_rawBits;  // “a” scaled by 2⁸
int rawB = r._rawBits;      // “b” scaled by 2⁸
long long num = (long long)rawA << _fbits;
// num == (a·2⁸) << 8 == (a·2⁸)·2⁸ == a·2¹⁶
long long div = num / rawB;
// div == (a·2¹⁶) / (b·2⁸) == (a/b)·2⁸
tmp._rawBits = (int)div;
// tmp._rawBits == (a/b)·2⁸  — the correct fixed-point encoding
return tmp;
// tmp now wraps the fixed-point result of a/b

Then streams tmp with operator<<

2.5f => 512₁₀ → 2⁹ + 128₁₀ → 2⁷ =>
      00000010 00000000₂
    + 00000000 10000000₂
    = 00000010 10000000₂
*/