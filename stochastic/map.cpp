#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include "person.h" 
#include "map.h"
#include "disease.h"

//the map object, we'll start out as a matrix for now
Map::Map(int width, int height) {
	rows = height;
	cols = width;

	srand(time(NULL));
	population = new Person*[rows];
	for (int i = 0; i < rows; i++) {
		population[i] = new Person[cols];
	}
	setEveryoneHealthy();
}

Map::~Map() {
	//for (int i = 0; i < rows; i++) {
		//free(population[i]);
	//}
	//free(population);
}

Person** Map::getGrid() {
	return population;
}

void Map::setEveryoneHealthy() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			population[i][j].setState('S');
		}
	}
	return;
}

void Map::random_seed(Disease& disease) {
	int rand_x = ((double)(rand() % 100) / 100) * rows;
	int rand_y = ((double)(rand() % 100) / 100) * cols;
	std::cout << "Random seed for disease " << disease.getName() << ": " << rand_x << "," << rand_y << std::endl;
	set_person_state(rand_x, rand_y, 'I');
	set_person_infection_time(rand_x, rand_y, disease.getAlpha());
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

void Map::print_test_map() {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << i << " " << j << " " << population[i][j].getState() << " ";
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


//This is needed fixed for ranges greater than 1
int Map::number_of_adjacent_inffected(int x, int y, int range) {
	int numInfected = 0;
	for (int i = 1; i <= range; i++) {
		if (x - i >= 0 && population[x - i][y].getState() == 'I') {
			numInfected++;
		}
		if (x + i < rows && population[x + i][y].getState() == 'I') {
			numInfected++;
		}
		if (y - i >= 0 && population[x][y - i].getState() == 'I') {
			numInfected++;
		}
		if (y + i < cols && population[x][y + i].getState() == 'I') {
			numInfected++;
		}
		if (y + i < cols && x + i < rows && population[x + i][y + i].getState() == 'I') {
			numInfected++;
		}
		if (y + i < cols && x - i >= 0 && population[x - i][y + i].getState() == 'I') {
			numInfected++;
		}
		if (y - i >= 0 && x - i >= 0 && population[x - i][y - i].getState() == 'I') {
			numInfected++;
		}
		if (y - i >=0 && x + i < rows && population[x + i][y - i].getState() == 'I') {
			numInfected++;
		}
	}
	return numInfected;
}
