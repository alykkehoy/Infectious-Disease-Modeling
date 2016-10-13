#include <iostream>
#include <string.h>
#include "person.h"

Person::Person(char s) {
	state = s;
	infectionTime = 0;
}

Person::Person() {
	Person('S');
}

void Person::set_infection_time(int time) {
	infectionTime = time;
}

int Person::get_infection_time() {
	return infectionTime;
}

char Person::getState(){
	return state;
}

void Person::setState(char s) {
	state = s;
	return;
}


