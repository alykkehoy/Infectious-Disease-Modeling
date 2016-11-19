/*

This file is a test run file for our disease libraries

*/

//include c++ libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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

int main(int argc, char** argv){
  if(argc != 1)//input file validation
  {
    cout << "Must have the name of a text file with no spaces as only argument" << endl;
    return 1;
  }
  string filename = argv[1];
  text_parse(); //take in parameters
/*
	//stuff for testing custom models
	std::vector<State*> model;
	S m_s();
	//model.push_back((State*)m_s);
	I i();
	//model.push_back(i);
	R r();
	//model.push_back(r);
	Model m_sir("SIR", model);*/


  int pop_width = 100;
  int pop_height = 30;
  int time = 50;
  int num_seeds = 1;

  analytics a("Analytics", pop_width  * pop_height, num_seeds);
  //a.set_pop_size(pop_width  * pop_height);
  //a.set_num_seeds(num_seeds);

  Disease disease("test", 3, 30, 10, 1, 2);

  Map map(pop_width, pop_height);
  for (int i = 0; i < num_seeds; i++) {
	  map.random_seed(disease);
  }
  //map.random_seed_immunity(30);

  SIR sir;
  SIRS sirs;
  SEIR seir;

  std::ofstream outfile("output.txt", std::ofstream::out);
  
  for (int loops = 0; loops < time; loops++) {
	  std::cout << "Time: " << loops << std::endl;
	  map.print_map();
	  map = sir.take_step(disease, a, map);
	  //map = sirs.take_step(disease, a, map);
	  //map = seir.take_step(disease, a, map);
  }
  
  std::cout << "Final: " << endl;
  map.print_map();

  map.print_immunity_map();
  map.print_num_infected_map();

  a.calc_analytics(map);
  a.print_delta_analytics();
  a.print_num_analytics();
  a.print_avg();

  outfile.close();
  
  return 0;
}
