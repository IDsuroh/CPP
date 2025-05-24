#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    std::cout << "\n==================== Default Test ====================\n";
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria*    tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\n\n==================== Custom Test ====================\n";
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria*    tmp;

        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    return 0;
}

/*
============================================================================================================
1. The Big-Picture Goal
You’re building a tiny “magic system” with three main pieces:

Materia (the spells or skills themselves)

Characters (who can equip and use Materia)

MateriaSource (a factory that “learns” some Materia blueprints and then can hand you fresh copies on demand)

Along the way, you get to prove you understand:

Abstract classes (pure-virtual methods = interfaces)

Polymorphism (calling methods through base-class pointers)

Prototype/clone pattern (virtual clone → virtual constructor)

Rule of Three (ctor, copy-ctor, copy-assign, dtor for any class that owns heap data)

Separation of interface vs implementation (headers vs .cpp’s)

============================================================================================================


2.The core concepts in play

Abstract class as “interface”

In C++98 there’s no interface keyword, but a class that has only pure-virtual methods is effectively one.

By programming to ICharacter* or IMateriaSource*, your high-level code doesn’t care which exact subclass it’s using.

Polymorphism & virtual dispatch

You store everything as pointers to the base or interface (AMateria*, ICharacter*, IMateriaSource*).

Calling use() or createMateria() dynamically dispatches to the right override in the concrete subclass.

Prototype (clone) pattern

You can never write a clean factory that does if(type=="ice") return new Ice; else if(type=="cure")…—that code explodes as you add new spells.

Instead, you “learn” a prototype (Ice*, Cure*) and later just call its clone() to get a brand-new copy of itself. This works even if you only hold an AMateria*.

Rule of Three & deep copy

Any class that owns raw pointers (e.g. Character owns AMateria* inventory[4]) must properly implement copy-ctor, copy-assign, destructor to avoid double-deletes or leaks.

You prove you did a deep copy by showing that, after copying, the two objects’ pointers are different but contain the same data.

Separation of concerns

Interfaces (.hpp only) define what operations are available.

Concrete classes (.hpp + .cpp) define how they do it.

Consumers (main.cpp) only see the interface, not the implementation details.


============================================================================================================
Visual metaphor

AMateria + Ice/Cure = blueprints/templates of different spells.

MateriaSource = the workshop/factory that you teach to “make” spells from those blueprints.

Character = the practitioner who carries a few spells in their spellbook (inventory) and can cast (use) them on a target.

*/