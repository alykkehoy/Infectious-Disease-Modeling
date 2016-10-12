#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include <iostream>
#include "Person.cpp"

class Map
{
    int rows;
    int cols;
    Person grid[rows][cols];

public:
    Map(rows, cols);
    
    Person getGrid();
    
};



#endif // GUARD_MAP_H