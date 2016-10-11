#ifndef GUARD_DISEASE
#define GUARD_DISEASE

#include <iostream>

class Person
{
    std::string name;
    enum State {S,I,R};
    

public:
    Person(std::string n, enum s);

    std::string getName();
    enum getState();

    std::string setName(std::string n);
    enum::setState(enum s);
    
};



#endif // GUARD_DISEASE
