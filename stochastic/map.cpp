#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "person.h" //for storing person objects
#include "map.h"
#include "disease.h"

Map::Map(int width, int height) {
	rows = height;
	cols = width;

	srand(time(NULL));
	Person** population;
	population = new Person*[rows];
	for (int i = 0; i < rows; i++) {
		population[i] = new Person[cols];
	}
	
	//Person** map = (Person**)malloc(rows * sizeof(Person*));
	//for (int i = 0; i < rows; i++) {
		//map[i] = (Person*)malloc(cols * sizeof(Person));
	//}
}
//the map object, we'll start out as a matrix for now

Map::~Map() {
	//for (int i = 0; i < rows; i++) {
		//free(population[i]);
	//}
	//free(population);
}

Person** Map::getGrid() {
	return population;
}


void Map::print_map() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << population[i][j].getState();
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	return;
}


void Map::set_person_state(int i, int j, char state) {
	population[i][j].setState(state);
}

void Map::set_person_infection_time(int i, int j, int time) {
	population[i][j].set_infection_time(time);
}

//TO DO
Map Map::take_step(Disease& disease, Map currentMap) {
	Map nextMap = currentMap;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (population[i][j].getState() == 'S') {
				for (int k = 0; k < number_of_adjacent_inffected(i, j, 1); k++) {
					if (rand() % 100 <= disease.getBeta()) {
						nextMap.set_person_state(i, j, 'I');
						nextMap.set_person_infection_time(i, j, disease.getAlpha());
					}
				}
			}
			if (population[i][j].getState() == 'I') {
				if (population[i][j].getState() == 0) {
					nextMap.set_person_state(i, j, 'R');
				}
				else {
					nextMap.set_person_infection_time(i, j, population[i][j].getState() - 1);
				}
			}
		}
	}
	return nextMap;
}

//This is needed fixed for ranges greater than 1
int Map::number_of_adjacent_inffected(int x, int y, int range) {
	int numInfected = 0;
	for (int i = 0; i < range; i++) {
		if (x - i >= 0 && population[x - i][y].getState() == 'I') {
			numInfected++;
		}
		if (x + i < cols && population[x + i][y].getState() == 'I') {
			numInfected++;
		}
		if (y - i >= 0 && population[x][y - i].getState() == 'I') {
			numInfected++;
		}
		if (y + i < rows && population[x][y + i].getState() == 'I') {
			numInfected++;
		}
		if (y + i < rows && x + i < cols && population[x + i][y + i].getState() == 'I') {
			numInfected++;
		}
		if (y + i < rows && x - i >= 0 && population[x - i][y + i].getState() == 'I') {
			numInfected++;
		}
		if (y - i >= 0 && x - i >= 0 && population[x - i][y - i].getState() == 'I') {
			numInfected++;
		}
		if (y - i >=0 && x + i < cols && population[x + i][y - i].getState() == 'I') {
			numInfected++;
		}
	}
	return numInfected;
}