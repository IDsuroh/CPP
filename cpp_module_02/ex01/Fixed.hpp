#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fbits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    Fixed(int const i);
    Fixed(float const f);

    float   toFloat(void)   const;
    int     toInt(void)     const;

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, Fixed const &fx);

#endif

/*
Fixed class is essentially a new numeric type—just like int or float—but implemented as a fixed-point number. Here’s what that means:

What Fixed class is?
- It’s not a container for “different types of variables.”
- It’s one single type whose job is to represent real (fractional) numbers by storing everything in one integer (_rawBits)
plus a compile-time constant scale factor (_fbits = 8).
- In C++ jargon, it is defining a user-defined arithmetic type with its own constructors, conversions, and stream-insertion overload.


What “fixed-point” means?
Unlike float or double (which use a floating-point format with a mantissa, exponent, and special bit patterns),
fixed-point arithmetic:
- Reserves a fixed number of bits for the fraction (in this case, 8 bits).
- Scales every real value by 2⁸ so that what would be the “fractional” part becomes an integer.
- Stores the result in a plain int.
- Divides (or bit-shifts) by 2⁸ to get back the real value when you need it.


Concretely:
Real value	| Stored |  _rawBits	|   Binary breakdown
    10.0	|         10 << 8 = 2560|	00001010 00000000₂ (2560)
    42.42	|roundf(42.42×256)=10860|	00101010 01110100₂ (10860)
- The high bits(left 8 digits) of _rawBits represent the integer part.
- The low 8 bits(right 8 digits) represent the fractional part (in steps of 1/256).

Why use fixed-point?
- Predictable precision & performance:
    Integer arithmetic (shifts, adds, multiplies) is often faster and deterministic on hardware without an FPU (floating-point unit).
- No rounding surprises of IEEE floats:
    Can control exactly how many fractional bits are kept.

- Common in embedded systems, audio DSP, graphics, and real-time applications where full IEEE floats
    are too heavyweight or where exact, reproducible behavior is needed.

*/