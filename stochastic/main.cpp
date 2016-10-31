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
#include "analytics.h"

using namespace std;

int main(){
	int pop_width = 100;
	int pop_height = 30;
  int time = 50;
  Analytics a;
  a.set_pop_size(pop_width  * pop_height);
  Map map(pop_width, pop_height);
  //test disease
  Disease disease("test", 5, 30);
  map.random_seed(disease);
  a.set_num_seeds(1);
  //map.random_seed(disease);


  
  for (int loops = 0; loops < time; loops++) {
	  std::cout << "Time: " << loops << std::endl;
	  map.print_map();
	  map = map.take_step(disease, a);
  }
  std::cout << "Final: " << std::endl;
  map.print_map();
  a.print_delta_analytics();
  a.print_num_analytics();
  //a.create_num_s();
  return 0;
}
