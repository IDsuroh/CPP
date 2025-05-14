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
    size_t idx = -1;
    for (size_t i = 0; i < (sizeof(angerlevel)/sizeof(*angerlevel)); ++i)  {
        if (angerlevel[i] == level) {
            idx = i;
            break ;
        }
    }
    switch (idx)    {
    case 0:
        debug();
        /* fall through */
    case 1:
        info();
        /* fall through */
    case 2:
        warning();
        /* fall through */
    case 3:
        error();
        break ;
    default:
        std::cout
            << "[ Probably complaining about insignificant problems ]"
            << std::endl;
    }
}

/*

This version of complain() does two things differently:

    It computes an index (idx) into your severity levels instead of
    immediately calling one handler, and

    It uses a switch with deliberate fall-through to cascade from
    the matched level up through the more severe ones.

sizeof(angerlevel) / sizeof(*angerlevel)
Classic C/C++ idiom for “number of elements in a statically-allocated array.”

sizeof(angerlevel)

    This gives you the total size in bytes of the whole array.

    Since angerlevel is a std::string[4], it’s roughly 4 * sizeof(std::string) bytes.

sizeof(*angerlevel)

    The array name angerlevel “decays” to a pointer in most expressions,
    but with sizeof it still refers to the array itself.

    Writing *angerlevel dereferences that array (i.e. gives you the first element),
    so sizeof(*angerlevel) is sizeof(std::string)—the size in bytes of one

total bytes for 4 strings
————————————————
  bytes for 1 string
= 4

The switch with fall-through:

case 0: calls debug(), then because there is no break;,
	execution “falls through” to case 1, then to case 2,
	and finally to case 3. You end up calling all four: debug(),
	then info(), then warning(), then error().

case 1: (when level == "INFO") calls info(), then falls through to call
	warning() and error().

case 2: calls warning(), then error().

case 3: calls error() only (and then hits the break; to exit the switch).

default: triggers if idx was still that “not found” value,
	so you print the catch-all message about insignificant problems.

fall through comment is extremely helpful because it suppresses compile warnings.
Especially since we are using -Wall flag.
*/