/*

This file is a test run file for our disease libraries

*/

//include c++ libraries
#include <iostream>
#include <string>
#include <vector>
#include <memory>

//include all of the other files in the program
//#include "neighborhood.h"
#include "map.h"
#include "disease.h"
#include "analytics.h"
#include "SIR.h"
#include "SIRS.h"
#include "SEIR.h"

#include "Model.h"

using namespace std;

int main(){

	//stuff for testing custom models
	std::vector<std::shared_ptr<State>> model;
	model.push_back(std::shared_ptr<State>(new S));
	//model.push_back(std::shared_ptr<State>(new E));
	model.push_back(std::shared_ptr<State>(new I));
	model.push_back(std::shared_ptr<State>(new R));
	//model.push_back(std::shared_ptr<State>(new S));
	Model m_sir("SIR", model);


  int pop_width = 100;
  int pop_height = 30;
  int time = 50;
  int num_seeds = 1;

  Disease disease("test", 3, 30, 10, 1, 2);

  Map map(pop_width, pop_height);
  for (int i = 0; i < num_seeds; i++) {
	  map.random_seed(disease);
  }
  
  for (int loops = 0; loops < time; loops++) {
	  std::cout << "Time: " << loops << std::endl;
	  map.print_map();
	  map = m_sir.take_step(disease, map);
  }

  cout << "Final: " << endl;
  map.print_map();

  map.print_immunity_map();
  map.print_num_infected_map();

  return 0;
}
