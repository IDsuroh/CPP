#include <iostream>
#include <string>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::cout << "Address of str: " << &str << std::endl;
    std::cout << "Address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;
    std::cout << "Value of str: " << str << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
    return 0;
}

/*
| Aspect                   | Pointer (`T*`)                                                                            | Reference (`T&`)                                                                              |
| ------------------------ | ----------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------- |
| **Definition**           | A variable that holds the *address* of another object.                                    | An *alias* (another name) for an existing object.                                             |
| **Syntax**               | Declaration: `T* p = &x;`<br>Access pointee: `*p`                                         | Declaration: `T& r = x;`<br>Access referent: `r`                                              |
| **Nullability**          | Can be null or uninitialized (`T* p = nullptr;`).                                         | Must be bound to a valid object on initialization—no “null” reference.                        |
| **Reseating**            | You can make a pointer point to different objects: `p = &y;`.                             | Once bound, a reference always refers to the same object.                                     |
| **Memory footprint**     | Occupies (usually) the size of an address (e.g. 8 bytes).                                 | Typically no extra storage—just another name for the original object.                         |
| **Arithmetic**           | Supports pointer arithmetic (`p+1`, `p–1`, indexing).                                     | No arithmetic—you can’t “move” a reference.                                                   |
| **Level of indirection** | Must explicitly dereference with `*` to access the pointee.                               | Implicit: you use `r` exactly like you’d use the original variable.                           |
| **Rebinding**            | Can be rebound at any time.<br> e.g. `int a, b; int* p = &a; p = &b;`                     | Cannot be rebound: once `int& r = a;` is set, you can’t later make `r` alias `b`.             |
| **Use cases**            | Dynamic data structures, arrays, optional semantics, APIs expecting “pointer or nullptr.” | Cleaner aliasing, operator overloading, “function in/out parameters” where null isn’t needed. |
*/