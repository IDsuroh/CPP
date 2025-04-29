#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include    "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int     _count;
    int     _nextIndex;
public:
    PhoneBook();
    void    add(const Contact& c);
    int     size() const;
    void    displayList() const;
    void    displayContact(int idx) const;
};

#endif