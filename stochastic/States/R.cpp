#include "R.h"

R::R() {
	char_representation = 'R';
}

R::~R() {

}

void R::take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map) {
	nextMap.set_person_state(i, j, 'R');
	return;
}
