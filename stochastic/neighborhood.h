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
  vector<pair<unsigned int, unsigned int>> findNeighbors(int x,
                                                         int y,
                                                         int magnitude,
                                                         neighbor n);

  vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Circle(unsigned int x,
                                                                          unsigned int y,
                                                                          unsigned int h,
                                                                          unsigned int w,
                                                                          unsigned int magnitude);

  vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Adjacent(unsigned int x,
                                                                            unsigned int y,
                                                                            unsigned int h,
                                                                            unsigned int w);

  vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Square(unsigned int x,
                                                                          unsigned int y,
                                                                          unsigned int h,
                                                                          unsigned int w,
                                                                          unsigned int magnitude);

private:

};

#endif //GUARD_NEIGHBORHOOD_H
