#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
    :   _count(0), _nextIndex(0)
{}

void    PhoneBook::add(const Contact& c)    {
    _contacts[_nextIndex] = c;
    if (_count < 8)
        ++_count;
    _nextIndex = (_nextIndex + 1) % 8;
}

int    PhoneBook::size() const {
    return  _count;
}

static std::basic_string<char>  truncate10(const std::basic_string<char>& s)    {
    if (s.size() <= 10) return s;
    return s.substr(0, 9) + '.';
}

void    PhoneBook::displayList() const  {
    std::cout
        << std::setw(10) << "Index"         << '|'
        << std::setw(10) << "First Name"    << '|'
        << std::setw(10) << "Last Name"     << '|'
        << std::setw(10) << "Nickname"      << '\n';
    for (int i = 0; i < _count; ++i)    {
        const Contact&  c = _contacts[i];
        std::cout
            << std::setw(10) << (i + 1)                         << '|'
            << std::setw(10) << truncate10(c.getFirstName())    << '|'
            << std::setw(10) << truncate10(c.getLastName())     << '|'
            << std::setw(10) << truncate10(c.getNickName())     << '\n';
    }
}

void    PhoneBook::displayContact(int idx) const    {
    if (idx < 0 || idx >= _count)   {
        std::cout << "Invalid index.\n";
        return ;
    }
    const Contact&  c = _contacts[idx];
    std::cout
        << "First Name:     " << c.getFirstName()       << '\n'
        << "Last Name:      " << c.getLastName()        << '\n'
        << "Nickname:       " << c.getNickName()        << '\n'
        << "Phone Number:   " << c.getPhoneNumber()     << '\n'
        << "Darkest Secret: " << c.getDarkestSecret()   << '\n';
}