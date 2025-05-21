#include "Harl.hpp"
#include <iostream>

void    Harl::debug( void )   {
    std::cout
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
        << std::endl;
}

void    Harl::info( void )    {
    std::cout
        << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
        << std::endl;
}

void    Harl::warning( void ) {
    std::cout
        << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
        << std::endl;
}

void    Harl::error( void )   {
    std::cout
        << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}

Harl::Harl()
{}

Harl::~Harl()
{}

void    Harl::complain( std::string level ) {
    static const std::string    angerlevel[] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    typedef void    (Harl::*HarlMemFn)();
    static const HarlMemFn  funcs[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (size_t i = 0; i < sizeof(angerlevel)/sizeof(*angerlevel); ++i) {
        if (angerlevel[i] == level) {
            (this->*funcs[i])();
            return ;
        }
    }
    std::cout << "[ Complaining to the Manager ]" << std::endl;
}

/*
An array of pointer-to-member-functions of Harl
typedef void (Harl::*HarlMemFn)();
	Says “HarlMemFn is the type “pointer to a Harl member function
	taking no args and returning void.”

static const HarlMemFn funcs[] = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
	Each entry is the address of one of Harl’s methods.
*/