#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include <iostream>
#include "Person.cpp"

class Map
{
private:
    int rows;
    int cols;
    Person grid[rows][cols];

public:
    //Map(rows, cols);
	void set_all_person_states(enum s);
	void print_map();
    Person getGrid();
	void take_step();
};



#endif // GUARD_MAP_H