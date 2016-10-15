#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "person.h" //for storing person objects
#include "map.h"
#include "disease.h"

Map::Map(unsigned int width, unsigned int height) {
	srand(time(NULL));
  Person map[width][height];
  set_all_person_states(S);
}
//the map object, we'll start out as a matrix for now

Person Map::getGrid() {
	return map;
}

void Map::set_all_person_states(enum s) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			map[i][j].setState(s);
		}
	}
	return;
}

//TO DO
void Map::print_map() {
	return;
}

