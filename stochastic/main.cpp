/*

This file is a test run file for our disease libraries

*/

//include c++ libraries
#include <iostream>
#include <string>

//include all of the other files in the program
//#include "neighborhood.h"
#include "person.h"
#include "map.h"
#include "disease.h"
#include "text_parse.h" //parse through simulation parameter text file
#include "Analytics.h"

using namespace std;

int main(){
  int time = 50;
  Analytics a;
  Map map(100, 30);
  //test disease
  Disease disease("test", 5, 30);
  map.random_seed(disease);
  //map.random_seed(disease);


  
  for (int loops = 0; loops < time; loops++) {
	  map = map.take_step(disease, a);
  }
  map.print_map();
  a.print_analytics();
  return 0;
}
