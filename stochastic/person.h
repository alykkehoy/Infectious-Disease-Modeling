#ifndef GUARD_PERSON_H
#define GUARD_PERSON_H

#include <iostream>

class Person
{
    enum State {S,I,R};
     

public:
    Person(std::string n, enum s);

    enum getState();

    enum::setState(enum s);
    
};



#endif // GUARD_DISEASE_H
