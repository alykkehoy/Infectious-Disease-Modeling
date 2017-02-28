/*
 *  @filename       Map.cpp
 *  @fileheader     Map.h
 *  @tile           Map
 *  @author         Team Infection
 *
 */
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include <string> 
#include <random> 
#include "Person.h"
#include "Map.h"
#include "Disease.h"

Map::Map(int width, int height) : rows(width), cols(height) {
    srand(time(NULL));
    std::default_random_engine generator{
            std::random_device()()
    };

    population = new Person *[rows];
    next_population = new Person *[rows];
    for (int i = 0; i < rows; i++) {
        population[i] = new Person[cols];
        next_population[i] = new Person[cols];
    }
    setEveryoneHealthy();
}

Map::Map(Map &original) {
    rows = original.get_rows();
    cols = original.get_cols();
    srand(time(NULL));
    std::default_random_engine generator{
            std::random_device()()
    };

    next_population = new Person *[rows];
    population = new Person *[rows];
    for (int i = 0; i < rows; i++) {
      next_population[i] = new Person[cols];
      population[i] = new Person[cols];
        for (int j = 0; j < cols; j++) {
            population[i][j].setState(original.get_person_state(i, j));
            population[i][j].set_immune(original.get_immune(i, j));
            population[i][j].set_incubation_timer(original.get_incubation_timer(i, j));
            population[i][j].set_infection_time(original.get_person_infection_time(i, j));
            population[i][j].set_num_infected(original.get_num_infected(i, j));
        }
    }
}

Map::~Map() {
    for (int i = 0; i < rows; i++) {
        delete[] population[i];
        delete[] next_population[i];
    }
    delete[] population;
    delete[] next_population;
    population = NULL;
    next_population = NULL;
}

Map &Map::operator=(Map
                    const &arg) {
    rows = arg.get_rows();
    cols = arg.get_cols();
    srand(time(NULL));
    std::default_random_engine generator{
            std::random_device()()
    };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            population[i][j].setState(arg.get_person_state(i, j));
            population[i][j].set_immune(arg.get_immune(i, j));
            population[i][j].set_incubation_timer(arg.get_incubation_timer(i, j));
            population[i][j].set_infection_time(arg.get_person_infection_time(i, j));
            population[i][j].set_num_infected(arg.get_num_infected(i, j));
        }
    }
    return *this;
}

Person **Map::getGrid() {
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

//this function generates a random infected person somewhere in the grid as well as an infection time
void Map::random_seed(Disease &disease) {
    std::default_random_engine generator{
            std::random_device()()
    };
    std::uniform_int_distribution<int> distribution(1, 100);
    int rand_x = ((double) distribution(generator) / 100) * rows;
    int rand_y = ((double) distribution(generator) / 100) * cols;

    std::cout << "Random seed for disease " << disease.getName() << ": " << rand_x << "," << rand_y << std::endl;
    set_person_state(rand_x, rand_y, 'I');
    set_person_infection_time(rand_x, rand_y, disease.getAlpha());
}

void Map::random_seed(Disease &disease, int num_seeds) {
    for (int i = 0; i < num_seeds; i++) {
        random_seed(disease);
    }
}

void Map::random_seed_immunity(int percent) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::default_random_engine generator{
                    std::random_device()()
            };
            std::uniform_int_distribution<int> distribution(1, 100);
            int rand = ((double) distribution(generator));
            if ((rand) <= percent) {
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
            } else {
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

char Map::get_person_state(int i, int j) const {
    return population[i][j].getState();
}

int Map::get_rows() const {
    return rows;
}

int Map::get_cols() const {
    return cols;
}

void Map::set_person_state(int i, int j, char state) {
    population[i][j].setState(state);
}

void Map::set_person_infection_time(int i, int j, int time) {
    population[i][j].set_infection_time(time);
}

int Map::get_person_infection_time(int i, int j) const {
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

int Map::get_num_infected(int i, int j) const {
    return population[i][j].get_num_infected();
}

void Map::set_immune(int i, int j, bool a) {
    population[i][j].set_immune(a);
}

bool Map::get_immune(int i, int j) const {
    return population[i][j].get_immune();
}

int Map::get_incubation_timer(int i, int j) const {
    return population[i][j].get_incubation_timer();
}

void Map::set_incubation_timer(int i, int j, int time) {
    population[i][j].set_incubation_timer(time);
}

void Map::set_next_incubation_timer(int i, int j, int time){
  next_population[i][j].set_incubation_timer(time);
}

void Map::set_next_person_state(int i, int j, char state){
  next_population[i][j].setState(state);
}

void Map::set_next_person_infection_time(int i, int j, int time){
  next_population[i][j].set_infection_time(time);
}

void Map::set_next_num_infected(int i, int j, int num){
  next_population[i][j].set_num_infected(num);
}

void Map::swap(){
  Person **temp = population;
  population = next_population;
  next_population = temp;
}
