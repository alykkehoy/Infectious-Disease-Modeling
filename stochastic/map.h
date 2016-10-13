#ifndef GUARD_MAP_H
#define GUARD_MAP_H
#include "person.h"

class Map
{
private:
	int rows;
	int cols;
	Person** map;

public:
	Map(unsigned int width, unsigned int height);
	~Map();
	Person ** getGrid();
	void print_map();
	void take_step();
};
#endif // GUARD_MAP_H