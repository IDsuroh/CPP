#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
private:
    std::string name;

    // Orthodox Canonical Form
public:
    Zombie();                           // Default constructor
    Zombie(std::string name);           // Parametrized constructor (Not part of the *OCF but its allowed to add)
    Zombie(const Zombie& other);              // Copy constructor 
    Zombie& operator=(const Zombie& other);   // Copy Assignment operator
    ~Zombie();                          // Destructor

    // Member functions
    void    announce(void) const;
    void    setName(const std::string& newName);
};

Zombie* zombieHorde(int N, std::string name);

#endif

/*  Orthodox Canonical Form
    - Destructor
    - Copy Constructor
    - Assignment Operator
    - Destructor

Default Constructor
    - Create a "fresh" object with its initial state.
    - Allocate or acquire any resouces.
    - Makes the object ready for use.
Copy Constructor
    - Create a new object as a copy of an existing object.
    - For pointers or handles, perform a deep copy which allocates and duplicates,
        rather than copying to avoid two objects sharing the same memory.
    - Makes the new object, which is the same exact copy of the original
        and the state of the original, ready for use.
Copy Assignment Operator
    - Assign the state of one object to another existing object.
    - Meaning, release whatever data was held.
    - Allocates new resources.
    - Copies the data from the source object to the destination object.
Destructor
    - Runs automatically whenever an object's lifetie is over.
    - Deletes memory and fclose open files or sockets and std::free C-style allocations.
    - Leaving no leaks.
    - no return value or parameters.
*/