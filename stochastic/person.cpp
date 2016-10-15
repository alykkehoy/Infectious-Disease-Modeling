<<<<<<< HEAD
#include <iostream>
#include <string.h>
#include "person.h"

Person::Person(enum s) {
	State = s;
}

enum Person::getState() {
	return State;
}
void Person::setState(enum s) {
	State = s;
	return;
}
