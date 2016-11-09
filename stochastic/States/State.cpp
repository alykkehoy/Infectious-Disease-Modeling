#include "State.h"
#include <memory>

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

char State::get_next_char_rep(std::vector<std::shared_ptr<State>> model) {
	for (int i = 0; i < model.size() - 1; i++) {
		if (model[i]->get_char_rep() == char_representation) {
			return model[i + 1]->get_char_rep();
		}
	}
	return char_representation;
}
