#ifndef GUARD_PERSON_H
#define GUARD_PERSON_H

#pragma once
class Person
{    
public:
	Person();
	Person(char s);
	~Person();

	void increment_num_infected(int num);

	void set_infection_time(int time);
	void setState(char s);
	void set_num_infected(int num);
	void set_immune(bool a);
	void set_incubation_timer(int i);

	int get_infection_time();
	char getState();
	int get_num_infected();
	bool get_immune();
	int get_incubation_timer();

private:
	char state;
	bool immune;
	int infectionTime;
	int num_infected;
	int incubation_timer;
};

#endif