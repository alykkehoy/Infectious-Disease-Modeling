#ifndef GUARD_PERSON_H
#define GUARD_PERSON_H

#include <iostream>

class Person
{
private:
    std::string name;
    enum State {S,I,R};
    
public:
    Person(std::string n, enum s);

    std::string getName();
    enum getState();

    void setName(std::string n);
    void setState(enum s);
    
};



#endif // GUARD_DISEASE_H
