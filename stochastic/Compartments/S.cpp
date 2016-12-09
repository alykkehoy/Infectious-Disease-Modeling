#include "S.h"

S::S() {
	char_representation = 'S';
}

S::~S() {

}

void S::take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map) {
	//VAR NAMES NEED CHANGED BELOW
	int x = j;
	int y = i;

	int range = disease.get_range();

	if (!current_map.get_immune(y, x)) {
		for (int k = -1 * range; k <= range; k++) {
			if (y + k >= 0 && y + k < current_map.get_rows()) {
				for (int l = -1 * range; l <= range; l++) {
					if (x + l >= 0 && x + l < current_map.get_cols()) {
						if (!(y + k == y && x + l == x)) {
							if (current_map.get_person_state(y + k, x + l) == 'I') {
								if (rand() % 100 <= disease.getBeta()) {
									nextMap.increment_num_infected(y + k, x + l);
									nextMap.set_person_state(y, x, next_char);
									nextMap.set_person_infection_time(y, x, disease.getAlpha());
									return;
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}
