#ifndef GUARD_MAP_H
#define GUARD_MAP_H

class Map
{
private:
    Person grid[int rows][int cols];

public:
    //Map(rows, cols) called grid because of potential name conflict
    //with std::map
    void setEveryoneHealthy();
    void printGrid();
    Person getGrid();
    bool isEnd(); //is it the end of the simulation?
};



#endif // GUARD_MAP_H
