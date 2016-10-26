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

int main(){
  //new disease
  int time = 25;
  Map map(25, 25);
  Map nextMap = map;
  Disease disease("test", 10, 10);
  map.set_person_state(0, 0, 'I');
  map.set_person_infection_time(0, 0, disease.getAlpha());
  map.print_map();

  
  
  for (int loops = 0; loops < time; loops++) {
	  map = map.take_step(disease, map);
	  map.print_map();
  }
  map.print_map();
  
  return 0;
}
