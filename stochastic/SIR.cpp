#include "SIR.h"
#include "map.h"
#include "stdlib.h"

SIR::SIR() {

}

SIR::~SIR() {

}

//Map SIR::take_step(Disease& disease) {
//	analytics a;
//	return take_step(disease, a);
//}

Map SIR::take_step(Disease& disease, analytics& a, Map& current_map) {
	int rows = current_map.get_rows();
	int cols = current_map.get_cols();
	Map nextMap(cols, rows);
	int delta_s = 0;
	int delta_i = 0;
	int delta_r = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (current_map.get_person_state(i, j) == 'S') {
				delta_s -= take_step_s(i, j, disease, nextMap, current_map);
			}
			else if (current_map.get_person_state(i, j) == 'I') {
				delta_i -= take_step_i(i, j, nextMap, current_map);
			}
			else if (current_map.get_person_state(i, j) == 'R') {
				take_step_r(i, j, nextMap, current_map);
			}
		}
	}

	a.add_to_delta_s(delta_s);
	a.add_to_delta_i(delta_i + (-1) * delta_s);
	a.add_to_delta_r(-1 * delta_i);
	return nextMap;
}

int SIR::take_step_s(int y, int x, Disease& disease, Map& nextMap, Map& current_map) {
	int range = disease.get_range();

	for (int k = -1 * range; k <= range; k++) {
		if (y + k >= 0 && y + k < current_map.get_rows()) {
			for (int l = -1 * range; l <= range; l++) {
				if (x + l >= 0 && x + l < current_map.get_cols()) {
					if (!(y + k == y && x + l == x)) {
						if (current_map.get_person_state(y + k, x + l) == 'I') {
							if (rand() % 100 <= disease.getBeta()) {
								nextMap.increment_num_infected(y + k, x + l);
								nextMap.set_person_state(y, x, 'I');
								nextMap.increment_num_infected(y, x, current_map.get_num_infected(y, x));
								nextMap.set_person_infection_time(y, x, disease.getAlpha());
								return 1;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

int SIR::take_step_i(int i, int j, Map& nextMap, Map& current_map) {
	int current_infection_time = current_map.get_person_infection_time(i, j);
	if (current_infection_time == 0) {
		nextMap.set_person_state(i, j, 'R');
		nextMap.increment_num_infected(i, j, current_map.get_num_infected(i, j));
		return 1;
	}
	else {
		nextMap.set_person_state(i, j, 'I');
		nextMap.increment_num_infected(i, j, current_map.get_num_infected(i, j));
		nextMap.set_person_infection_time(i, j, current_infection_time - 1);
		return 0;
	}
}

int SIR::take_step_r(int i, int j, Map& nextMap, Map& current_map) {
	nextMap.set_person_state(i, j, 'R');
	nextMap.increment_num_infected(i, j, current_map.get_num_infected(i, j));
	return 0;
}
