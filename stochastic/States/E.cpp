#include "E.h"

E::E() {
	char_representation = 'E';
}

E::~E() {

}

void E::take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map, std::vector<std::shared_ptr<State>> model) {
	char next_char = get_next_char_rep(model);
	if (current_map.get_incubation_timer(i, j) == 0) {
		nextMap.set_person_state(i, j, next_char);
		nextMap.set_person_infection_time(i, j, disease.getAlpha());
		return;
	}
	else {
		nextMap.set_person_state(i, j, char_representation);
		nextMap.set_incubation_timer(i, j, current_map.get_incubation_timer(i, j) - 1);
	}
	return;
}
