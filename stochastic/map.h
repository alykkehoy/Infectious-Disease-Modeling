#ifndef GUARD_MAP_H
#define GUARD_MAP_H

class Map
{
private:
    int rows;
    int cols;
    Person grid[rows][cols];

public:
    //Map(rows, cols);
    void setEveryoneHealthy();
    void print_map();
    Person getGrid();
    bool isEnd(); //is it the end of the simulation?
};



#endif // GUARD_MAP_H
