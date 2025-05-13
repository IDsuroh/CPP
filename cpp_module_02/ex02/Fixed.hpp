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

// Comparison operators (>, <, >=, <=, ==, !=)
    bool operator>  (Fixed const& rhs)  const;
    bool operator<  (Fixed const& rhs)  const;
    bool operator>= (Fixed const& rhs)  const;
    bool operator<= (Fixed const& rhs)  const;
    bool operator== (Fixed const& rhs)  const;
    bool operator!= (Fixed const& rhs)  const;

// Arithmetic operators (+, -, *, /)
    Fixed operator+ (Fixed const& rhs)  const;
    Fixed operator- (Fixed const& rhs)  const;
    Fixed operator* (Fixed const& rhs)  const;
    Fixed operator/ (Fixed const& rhs)  const;

// Increment/decrement (pre- and post- ++/--)
    Fixed&  operator++();
    Fixed   operator++(int);
    Fixed&  operator--();
    Fixed   operator--(int);

// Static min/max helpers
    static Fixed&   min(Fixed& a, Fixed& b);
    static Fixed&   max(Fixed& a, Fixed& b);
    static Fixed const& min(Fixed const& a, Fixed const& b);
    static Fixed const& max(Fixed const& a, Fixed const& b);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, Fixed const &fx);

#endif