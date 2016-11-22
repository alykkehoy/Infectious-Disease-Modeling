#ifndef GUARD_NEIGHBORHOOD_H
#define GUARD_NEIGHBORHOOD_H

//takes in map and neighborhood parameters and returns matrix of pairs (coord)

class Neighborhood
{

private:
  enum pattern;   

public:
  std::vector<std::pair<unsigned int, unsigned int>> getNeighbors(enum pattern, std::pair<unsigned int, unsigned int>);

   
};

#endif //GUARD_NEIGHBORHOOD_H
