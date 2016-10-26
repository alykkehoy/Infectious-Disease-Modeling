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

using namespace std;

int main(){
  //new disease
  int time = 50;
  Map map(100, 30);
  Disease disease("test", 10, 50);
  map.set_person_state(0, 0, 'I');
  map.set_person_infection_time(0, 0, disease.getAlpha());
  //map.print_test_map();

  
  
  for (int loops = 0; loops < time; loops++) {
	  cout << "Time: " << loops << endl;
	  map.print_map();
	  map = map.take_step(disease);
  }
  return 0;
}
