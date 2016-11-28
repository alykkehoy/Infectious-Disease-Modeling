#ifndef GUARD_NEIGHBORHOOD_H
#define GUARD_NEIGHBORHOOD_H

#include <vector>
#include <utility>

using std::vector;
using std::pair;

//takes in map and neighborhood parameters and returns vector of pairs (coord)

class Neighborhood
{

public:
  enum area {circle, adjacent, square};
  vector<pair<unsigned int, unsigned int>> findNeighbors(int x, int y,
                                                         int magnitude, neighbor n);

  vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Circle();

  vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Adjacent();

  vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Square();

private:

};

#endif //GUARD_NEIGHBORHOOD_H
