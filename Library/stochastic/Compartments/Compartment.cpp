#include "Compartment.h"
#include <memory>

Compartment::Compartment() {
	
}

Compartment::~Compartment() {

}

char Compartment::get_char_rep() {
	return char_representation;
}

void Compartment::set_char_rep(char c) {
	char_representation = c;
}

void Compartment::create_next_char(std::vector<std::shared_ptr<Compartment>> model) {
	for (int i = 0; i < model.size() - 1; i++) {
		if (model[i]->get_char_rep() == char_representation) {
			next_char = model[i + 1]->get_char_rep();
			return;
		}
	}
	next_char = char_representation;
	return;
}
