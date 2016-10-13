#include <iostream>
#include <string.h>
#include "person.h"

Person::Person(string n, enum s) {
	name = n;
	State = s;
}

string Person::getName() {
	return name;
}
enum Person::getState() {
	return State;
}
void Person::setName(string n) {
	name = n;
	return;
}
void Person::setState(enum s) {
	State = s;
	return;
}

