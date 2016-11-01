#ifndef GUARD_PERSON_H
#define GUARD_PERSON_H

#pragma once
class Person
{    
public:
	Person();
	void set_infection_time(int time);
	int get_infection_time();
    Person(char s);
	char getState();
    void setState(char s);
	int get_num_infected();
	void increment_num_infected();
private:
	char state;
	int infectionTime;
	int num_infected;
};

#endif