#include "Harl.hpp"
#include <iostream>

void    Harl::debug( void )   {
    std::cout
        << "[ DEBUG ]" << std::endl
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl
        << "I really do!" << std::endl
        << std::endl;
}

void    Harl::info( void )    {
    std::cout
        << "[ INFO ]" << std::endl
        << "I cannot believe adding extra bacon costs more money." << std::endl 
        << "You didn't put enough bacon in my burger!" << std::endl
        << "If you did, I wouldn't be asking for more!" << std::endl
        << std::endl;
}

void    Harl::warning( void ) {
    std::cout
        << "[ WARNING ]" << std::endl
        << "I think I deserve to have some extra bacon for free." << std::endl
        << "I've been coming for years, whereas you started working here just last month." << std::endl
        << std::endl;
}

void    Harl::error( void )   {
    std::cout
        << "[ ERROR ]" << std::endl
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
            while (i < sizeof(angerlevel)/sizeof(*angerlevel))  {
                (this->*funcs[i])();
                i++;
            }
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}