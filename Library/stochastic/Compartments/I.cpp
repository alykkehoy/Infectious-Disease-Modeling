#include "I.h"

I::I() {
	char_representation = 'I';
}

I::~I() {

}

void I::take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map) {
	int current_infection_time = current_map.get_person_infection_time(i, j);
	if (current_infection_time == 0) {
		nextMap.set_person_state(i, j, next_char);
		return;
	}
	else {
		nextMap.set_person_state(i, j, 'I');
		nextMap.set_person_infection_time(i, j, current_infection_time - 1);
		return;
	}
}
