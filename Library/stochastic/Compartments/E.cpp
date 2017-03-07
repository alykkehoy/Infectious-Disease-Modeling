#include "E.h"

E::E() {
	char_representation = 'E';
}

E::~E() {

}

bool E::take_step(int i, int j, Disease& disease, Map& current_map) {
	if (current_map.get_incubation_timer(i, j) == 0) {
		current_map.set_next_person_state(i, j, next_char);
		current_map.set_next_person_infection_time(i, j, disease.getAlpha());
		return true;
	}
	else {
		current_map.set_next_person_state(i, j, char_representation);
		current_map.set_next_incubation_timer(i, j, current_map.get_incubation_timer(i, j) - 1);
	}
	return false;
}
