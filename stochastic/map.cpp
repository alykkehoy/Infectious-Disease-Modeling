#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <random>
#include "person.h" 
#include "map.h"
#include "disease.h"

//the map object
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
			population[i][j].set_immune(false);
		}
	}
	return;
}

//this function generates a random infected person somewhere in the grud as well as an infection time
void Map::random_seed(Disease& disease) {
	std::default_random_engine generator { std::random_device()() };
	std::uniform_int_distribution<int> distribution(1,100);
	int rand_x = ((double)distribution(generator));
	int rand_y = ((double)distribution(generator));
	std::cout << "Random seed for disease " << disease.getName() << ": " << rand_x << "," << rand_y << std::endl;
	set_person_state(rand_x, rand_y, 'I');
	set_person_infection_time(rand_x, rand_y, disease.getAlpha());
}

void Map::random_seed_immunity(int percent) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if ((rand() % 100 + 1) <= percent) {
				population[i][j].set_immune(true);
			}
		}
	}
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

void Map::print_num_infected_map() {
	std::cout << "Number of people infected by a person:" << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << population[i][j].get_num_infected();
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	return;
}

void Map::print_immunity_map() {
	std::cout << "Immunity map:" << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (population[i][j].get_immune()) {
				std::cout << 'Y';
			}
			else {
				std::cout << 'N';
			}
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

char Map::get_person_state(int i, int j) {
	return population[i][j].getState();
}

int Map::get_rows() {
	return rows;
}

int Map::get_cols() {
	return cols;
}

void Map::set_person_state(int i, int j, char state) {
	population[i][j].setState(state);
}

void Map::set_person_infection_time(int i, int j, int time) {
	population[i][j].set_infection_time(time);
}

int Map::get_person_infection_time(int i, int j) {
	return population[i][j].get_infection_time();
}

void Map::increment_num_infected(int i, int j, int num) {
	population[i][j].increment_num_infected(num);
}

void Map::increment_num_infected(int i, int j) {
	increment_num_infected(i, j, 1);
}

void Map::set_num_infected(int i, int j, int num) {
	population[i][j].set_num_infected(num);
}

int Map::get_num_infected(int i, int j) {
	return population[i][j].get_num_infected();
}

void Map::set_immune(int i, int j, bool a) {
	population[i][j].set_immune(a);
}

bool Map::get_immune(int i, int j) {
	return population[i][j].get_immune();
}

int Map::get_incubation_timer(int i, int j) {
	return population[i][j].get_incubation_timer();
}

void Map::set_incubation_timer(int i, int j, int time) {
	population[i][j].set_incubation_timer(time);
}
