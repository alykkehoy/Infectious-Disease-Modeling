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
    cerr << "Check your dimensions. Width of map is less than transmission area width" << endl;
    error = true;
  }

  if(magnitude < 0) //negative distance
  {
    cerr << "Check your magnitude, it's less than zero" << endl;
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


vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Circle(x, y, magnitude)
{
  //Brensenham's midpoint circle algorithm
  int e = -1 * magnitude; //E = -R
  int x = magitude; //X = R
  int y = 0; //Y = 0



}

vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Adjacent(x, y, magnitude)
{

}

vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Square(x, y, magnitude)
{

}
