#include "R.h"

R::R() {
	char_representation = 'R';
}

R::~R() {

}

void R::take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map) {
	if (rand() % 100 <= disease.get_mortality_rate()) {
		nextMap.set_person_state(i, j, 'R');
		//nextMap.set_immune(i, j, true);
		return;
	}
	nextMap.set_person_state(i, j, next_char);
	return;
}
