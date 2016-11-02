/*

This file is a test run file for our disease libraries

*/

//include c++ libraries
#include <iostream>
#include <string>

//include all of the other files in the program
//#include "neighborhood.h"
#include "map.h"
#include "disease.h"
#include "analytics.h"
#include "SIR.h"
#include "SIRS.h"

using namespace std;

int main(){
  int pop_width = 100;
  int pop_height = 30;
  int time = 50;
  int num_seeds = 1;

  analytics a("Analytics", pop_width  * pop_height, num_seeds);
  //a.set_pop_size(pop_width  * pop_height);
  //a.set_num_seeds(num_seeds);

  Disease disease("test", 3, 30, 10, 1);

  Map map(pop_width, pop_height);
  for (int i = 0; i < num_seeds; i++) {
	  map.random_seed(disease);

  }


  SIR sir;
  SIRS sirs;

  
  for (int loops = 0; loops < time; loops++) {
	  std::cout << "Time: " << loops << std::endl;
	  map.print_map();
	  map = sir.take_step(disease, a, map);
	  //map = sirs.take_step(disease, a, map);
  }

  cout << "Final: " << endl;
  map.print_map();

  map.print_num_infected_map();

  a.print_delta_analytics();
  a.print_num_analytics();
  a.create_avg_num_infected(map);
  a.print_avg();

  return 0;
}
