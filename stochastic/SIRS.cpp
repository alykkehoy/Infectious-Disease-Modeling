#include "SIRS.h"
#include "map.h"

SIRS::SIRS() {

}

SIRS::~SIRS() {

}

Map SIRS::take_step(Disease& disease, analytics& a, Map& current_map) {
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
				take_step_r(i, j,disease, nextMap);
			}
		}
	}

	a.add_to_delta_s(delta_s);
	a.add_to_delta_i(delta_i + (-1) * delta_s);
	a.add_to_delta_r(-1 * delta_i);
	return nextMap;
}

int SIRS::take_step_s(int i, int j, Disease& disease, Map& nextMap, Map& current_map) {
	for (int k = 0; k < current_map.number_of_adjacent_inffected(i, j, disease.get_range()); k++) {
		if (rand() % 100 <= disease.getBeta()) {
			nextMap.set_person_state(i, j, 'I');
			nextMap.set_person_infection_time(i, j, disease.getAlpha());
			return 1;
		}
	}
	return 0;
}

int SIRS::take_step_i(int i, int j, Map& nextMap, Map& current_map) {
	int current_infection_time = current_map.get_person_infection_time(i, j);
	if (current_infection_time == 0) {
		nextMap.set_person_state(i, j, 'R');
		return 1;
	}
	else {
		nextMap.set_person_state(i, j, 'I');
		nextMap.set_person_infection_time(i, j, current_infection_time - 1);
		return 0;
	}
}

int SIRS::take_step_r(int i, int j, Disease& disease, Map& nextMap) {
	if (rand() % 100 <= disease.get_mortality_rate()) {
		nextMap.set_person_state(i, j, 'R');
		return 1;
	}
	nextMap.set_person_state(i, j, 'S');
	return 0;
}
