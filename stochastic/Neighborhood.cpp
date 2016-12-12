/*
 *  @filename       Neighborhood.cpp
 *  @fileheader     Neighborhood.h
 *  @tile           Neighborhood
 *  @author         Team Infection
 *
 */
#include <utility>
#include "Neighborhood.h"
#include "Map.h"

using std::vector;
using std::pair;
using std::endl;
using std::cerr;
using std::make_pair;

//neighborhood object, will return what the neighborhood for a cell is
vector <pair<unsigned int, unsigned int>> Neighborhood::findNeighbors(int x, int y,
                                                                      int magnitude, area n, Map &map) {
    unsigned int h = map.get_rows(); //height
    unsigned int w = map.get_cols(); //width
    //error checking
    bool error = false;

    if (h < (magnitude * 2)) //magnitude is doubled in calculation below(i.e. radius)
    {
        cerr << "Check your dimensions. Height of map is less than transmission area height" << endl;
        error = true;
    }

    if (w < (magnitude * 2)) //magnitude is doubled in calculation below(i.e. radius)
    {
        cerr << "Check your dimensions. Width of map is less than transmission area width" << endl;
        error = true;
    }

    if (magnitude < 0) //negative distance
    {
        cerr << "Check your magnitude, it's less than zero" << endl;
    }

    if (error) exit(1); //exit the program


    //calculate area and shape
    switch (n) {
        case circle:
            return Neighborhood::calculate_Circle(x, y, h, w, magnitude);
        case adjacent: //right next to infected (no diagonals)
            return Neighborhood::calculate_Cross(x, y, h, w, magnitude);
        case square:
            return Neighborhood::calculate_Square(x, y, h, w, magnitude);
    }
}


vector <pair<unsigned int, unsigned int>> Neighborhood::calculate_Circle(x, y, h, w, magnitude) {
    //midpoint circle algorithm https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
    int e = -1 * magnitude; //E = -R
    int x = magitude; //X = R
    int y = 0; //Y = 0

}

//can return pointers to people objects
//mapping of coord to people
vector <pair<unsigned int, unsigned int>> Neighborhood::calculate_Cross(unsigned int x,
                                                                        unsigned int y,
                                                                        unsigned int h,
                                                                        unsigned int w,
                                                                        unsigned int magnitude) {
    vector <pair<unsigned int, unsigned int>> n; //neighbors

    //current comparative values
    unsigned int x_neg = x;
    unsigned int x_pos = x;
    unsigned int y_neg = y;
    unsigned int y_pos = y;

    for (unsigned int i = 1; i <= magnitude; i++) //loop through neighbors with magnitude into account
    {
        //take step left, then push to vector
        x_neg = oneLeft(x_neg, w);
        n.push_back(make_pair(x_neg, y));

        //take step right, then push to vector
        x_pos = oneRight(x_pos, w);
        n.push_back(make_pair(x_pos, y));

        //take step up, then push to vector
        y_pos = oneUp(y_pos, h);
        n.push_back(make_pair(x, y_pos));

        //take step down, then push to vector
        y_neg = oneDown(y_neg, h);
        n.push_back(make_pair(x, y_neg));
    }

    return n;
}


vector <pair<unsigned int, unsigned int>> Neighborhood::calculate_Square(unsigned int x,
                                                                         unsigned int y,
                                                                         unsigned int h,
                                                                         unsigned int w,
                                                                         unsigned int magnitude) {
    vector <pair<unsigned int, unsigned int>> n; //neighbors
    unsigned int cursor_x = x;
    unsigned int cursor_y = y;

    //go up and push center row
    for (unsigned int mag_count_y = 0;
         mag_count_y <= magnitude; mag_count_y++, cursor_y++) //until reach max of magnitude
    {
        //go left
        for (unsigned int mag_count_x = 0; mag_count_x < magnitude; mag_count_x++) {
            cursor_x = oneLeft(cursor_x, w);
            n.push_back(make_pair(cursor_x, cursor_y));
        }
        //reset cursor
        cursor_x = x;
        //go right
        for (unsigned int mag_count_x = 0; mag_count_x < magnitude; mag_count_x++) {
            cursor_x = oneRight(cursor_x, w);
            n.push_back(make_pair(cursor_x, cursor_y));
        }
        //reset cursor
        cursor_x = x;
        //push center
        n.push_back(make_pair(cursor_x, cursor_y));

    }
    //set y_cursor to one below middle row
    cursor_y = y - 1;


    //go down not including center row
    for (unsigned int mag_count_y = 1;
         mag_count_y <= magnitude; mag_count_y++, cursor_y--) //until reach min of magnitude
    {
        //go left
        for (unsigned int mag_count_x = 0; mag_count_x < magnitude; mag_count_x++) {
            cursor_x = oneLeft(cursor_x, w);
            n.push_back(make_pair(cursor_x, cursor_y));
        }
        //reset cursor
        cursor_x = x;
        //go right
        for (unsigned int mag_count_x = 0; mag_count_x < magnitude; mag_count_x++) {
            cursor_x = oneRight(cursor_x, w);
            n.push_back(make_pair(cursor_x, cursor_y));
        }
        //reset cursor
        cursor_x = x;
        //push center
        n.push_back(make_pair(cursor_x, cursor_y));
    }

    return n;
}


int oneUp(unsigned int y, unsigned int h) {
    //up (++y)
    if (y == h) // bounds checking: at top of map, up neighbor is bottom
    {
        return 0;
    } else {
        ++y;
        return y;
    }
}

int oneDown(unsigned int y, unsigned int h) {
    //down (--y)
    if (y == 0) // bounds checking: at bottom of map, down neighbor is top
    {
        return h;
    } else {
        --y;
        return y;
    }
}

int oneLeft(unsigned int x, unsigned int w) {
    //left (-x)
    if (x == 0) // bounds checking: at left of map, left neighbor is right
    {
        x = w;
        return x;
    } else {
        --x;
        return x;
    }
}

int oneRight(unsigned int x, unsigned int w) {
    //right (+x)
    if (x == w) // bounds checking: at right of map, right neighbor is left
    {
        x = 0;
        return x;
    } else {
        ++x;
        return x;
    }
}
