#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "person.h"
#include "disease.h"

class Person;
class Map
{
public:
	void setEveryoneHealthy();
	Map(int width, int height);
	~Map();
	Person** getGrid();
	void random_seed(Disease& disease);
	void random_seed_immunity(int percent);
	void print_map();
	void print_num_infected_map();
	void print_immunity_map();
	void print_test_map();
	int get_rows();
	int get_cols();
	void set_person_state(int i, int j, char state);
	char get_person_state(int i, int j);
	int get_person_infection_time(int i, int j);
	void set_person_infection_time(int i, int j, int time);
	void set_num_infected(int i, int j, int num);
	int get_num_infected(int i, int j);
	void increment_num_infected(int i, int j);
	void increment_num_infected(int i, int j, int num);
	void set_immune(int i, int j, bool a);
	bool get_immune(int i, int j);

private:
	Person** population;
	int rows;
	int cols;

};
#endif // GUARD_MAP_H
