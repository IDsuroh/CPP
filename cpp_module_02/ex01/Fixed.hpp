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