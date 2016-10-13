#ifndef GUARD_MAP_H
#define GUARD_MAP_H
#include "person.h"
#include "disease.h"

class Person;
class Map
{
public:
	Map(int width, int height);
	~Map();
	Person** getGrid();
	void print_map();
	void set_person_state(int i, int j, char state);
	void set_person_infection_time(int i, int j, int time);
	Map take_step(Disease& disease, Map currentMap);
	int number_of_adjacent_inffected(int x, int y, int range);
private:
	int rows;
	int cols;
	Person** population;
};
#endif // GUARD_MAP_H