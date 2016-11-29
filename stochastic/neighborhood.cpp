#include <utility>
#include "neighborhood.h"
#include "map.h"

using std::vector;
using std::pair;
using std::endl;
using std::cerr;

//neighborhood object, will return what the neighborhood for a cell is
vector<pair<unsigned int, unsigned int>> Neighborhood::findNeighbors(int x, int y,
                                                      int magnitude, area n, Map& map)
{

  //error checking
  bool error = false;
  if(map.get_rows() < (magnitude * 2)) //magnitude is doubled in calculation below(i.e. radius)
  {
    cerr << "Check your dimensions. Height of map is less than transmission area height" << endl;
    error = true;
  }
  if(map.get_cols() < (magnitude * 2)) //magnitude is doubled in calculation below(i.e. radius)
  {
    cerr << "Error opening parameter file for simulation" << endl;
    error = true;
  }
  if(error) exit(1); //exit the program


  //calculate area and shape
  switch(n)
  {
    case circle:
      return Neighborhood::calculate_Circle(x, y, magnitude);
    case adjacent:
      return Neighborhood::calculate_Adjacent(x, y, magnitude);
    case square:
      return Neighborhood::calculate_Square(x, y, magnitude);
  }
}

vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Circle()
{

}

vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Adjacent()
{

}

vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Square()
{

}
