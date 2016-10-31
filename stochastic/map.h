#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "person.h"
#include "disease.h"
#include "analytics.h"

class Person;
class Map
{
public:
	void setEveryoneHealthy();
	Map(int width, int height);
	~Map();
	Person** getGrid();
	void random_seed(Disease& disease);
	void print_map();
	void print_test_map();
	int get_rows();
	int get_cols();
	void set_person_state(int i, int j, char state);
	char get_person_state(int i, int j);
	void set_person_infection_time(int i, int j, int time);
	int number_of_adjacent_inffected(int x, int y, int range);

private:
	Person** population;
	int rows;
	int cols;

};
#endif // GUARD_MAP_H
