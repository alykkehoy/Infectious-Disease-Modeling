#ifndef GUARD_PERSON_H
#define GUARD_PERSON_H

class Person
{    
public:
	enum State { S, I, R };
	Person();
    Person(State s);

	char getState();
    void setState(State s);
private:
	State state;
};



#endif // GUARD_DISEASE_H
