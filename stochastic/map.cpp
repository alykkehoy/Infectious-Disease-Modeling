#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "person.h" //for storing person objects
#include "map.h"
#include "disease.h"

Map::Map(unsigned int width, unsigned int height) {
	rows = height;
	cols = width;

	srand(time(NULL));
	Person** map = new Person*[rows];
	for (int i = 0; i < rows; i++) {
		map[i] = new Person[cols];
	}
}
//the map object, we'll start out as a matrix for now

Map::~Map() {
	for (int i = 0; i < rows; i++) {
		delete[] map[i];
	}
	delete[] map;

}

Person** Map::getGrid() {
	return map;
}


//TO DO
void Map::print_map() {
	return;
}


//TO DO
void Map::take_step() {

}