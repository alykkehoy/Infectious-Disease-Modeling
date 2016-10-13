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
private:
	char state;
	int infectionTime;
};
