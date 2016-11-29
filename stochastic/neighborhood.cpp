#include <utility>
#include "neighborhood.h"
#include "map.h"

using std::vector;
using std::pair;
using std::endl;
using std::cerr;
using std::make_pair;

//neighborhood object, will return what the neighborhood for a cell is
vector<pair<unsigned int, unsigned int>> Neighborhood::findNeighbors(int x, int y,
                                                      int magnitude, area n, Map& map)
{
  unsigned int h = map.get_rows(); //height
  unsigned int w = map.get_cols(); //width
  //error checking
  bool error = false;

  if(h < (magnitude * 2)) //magnitude is doubled in calculation below(i.e. radius)
  {
    cerr << "Check your dimensions. Height of map is less than transmission area height" << endl;
    error = true;
  }

  if(w < (magnitude * 2)) //magnitude is doubled in calculation below(i.e. radius)
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
      return Neighborhood::calculate_Circle(x, y, h, w, magnitude);
    case adjacent: //right next to infected (no diagonals)
      return Neighborhood::calculate_Adjacent(x, y, h, w);
    case square:
      return Neighborhood::calculate_Square(x, y, h, w, magnitude);
  }
}


vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Circle(x, y, h, w, magnitude)
{
  //Brensenham's midpoint circle algorithm
  int e = -1 * magnitude; //E = -R
  int x = magitude; //X = R
  int y = 0; //Y = 0



}

vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Adjacent(x, y, h, w)
{
  vector<pair<unsigned int, unsigned int>> n; //neighbors

  //up (y++)
  if((y + 1) > h) n.push_back(make_pair(x, 0)); //at top of map, up neighbor is bottom
  else n.push_back(make_pair(x, ++y));
  //down
  if((y - 1) < 0) n.push_back(make_pair(x, h)); //at bottom of map, down neighbor is top
  else n.push_back(make_pair(x, --y));
  //left
  if ((x - 1) < 0) n.push_back(make_pair(w, y)); //at left of map, left neighbor is right
  else n.push_back(make_pair(--x, y));
  //right
  if ((x + 1) > w) n.push_back(make_pair(0, y)); //at right of map, right neighbor is left
  else n.push_back(make_pair(++x, y));

  return n;
}

vector <pair<unsigned int, unsigned int>>Neighborhood::calculate_Square(x, y, h, w, magnitude)
{

}
