#ifndef GUARD_MAP_H
#define GUARD_MAP_H

class Map
{
    unsigned int rows;
    unsigned int cols;
    Person world[rows][cols];

public:
    Map(rows, cols);
     
    Person getPerson(unsigned int row,unsigned int col);
    void setPerson(unsigned int row, unsigned int col);
    void startWorld();
};



#endif // GUARD_MAP_H
