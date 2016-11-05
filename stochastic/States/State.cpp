#include "State.h"

State::State() {
	
}

State::~State() {

}

char State::get_char_rep() {
	return char_representation;
}

void State::set_char_rep(char c) {
	char_representation = c;
}