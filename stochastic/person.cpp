#include <iostream>
#include <string.h>
#include "person.h"

Person::Person(State s) {
	state = s;
}

Person::Person() {
	Person(S);
}


char Person::getState(){
	switch(state) {
		case S:
			return 'S';
		case I:
			return 'I';
		case R:
			return 'R';
		default:
			return '\0';
	}
}

void Person::setState(State s) {
	state = s;
	return;
}
