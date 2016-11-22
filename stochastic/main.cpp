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
#include "text_parse.h";

using std::cout;
using std::endl;

int main(int argc, char** argv){
  if(argc != 1)//input file validation
  {
    cout << "Must have the name of a text file with no spaces as only argument" << endl;
    return 1;
  }
  string filename = argv[1];
  Text_parse::Text_parse(filename); //take in parameters
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

  //I don't know what this does
  int num_seeds = 1;

  Text_parse parser(filename);
  //get variables
  string diseaseModel = parser.getDiseaseModel();
  int sim_len = parser.getSim_len();
  int pop_width = parser.getPop_width();
  int pop_height = parser.getPop_height();

  analytics a("Analytics", pop_width  * pop_height, num_seeds);
  //a.set_pop_size(pop_width  * pop_height);
  //a.set_num_seeds(num_seeds);


  //initialize disease
  Disease disease("test", 3, 30, 10, 1, 2);

  //initialize map according to disease
  Map map(pop_width, pop_height);
  for (int i = 0; i < num_seeds; i++) {
	  map.random_seed(disease);
  }
  //map.random_seed_immunity(30);

  std::ofstream outfile("output.txt", std::ofstream::out);

  //implement different simulations based on input
  if(diseaseModel == "SIR")
  {
    SIR sir;
    for (int loops = 0; loops < sim_len; loops++) {
      std::cout << "Time: " << loops << std::endl;
      map.print_map();
      map = sir.take_step(disease, a, map);
    }
  }
  else if(diseaseModel == "SIRS")
  {
    SIRS sirs;
    for (int loops = 0; loops < sim_len; loops++) {
      std::cout << "Time: " << loops << std::endl;
      map.print_map();
      map = sirs.take_step(disease, a, map);
    }
  }
  else if(diseaseModel == "SEIR")
  {
    SEIR seir;
    for (int loops = 0; loops < sim_len; loops++) {
      std::cout << "Time: " << loops << std::endl;
      map.print_map();
      map = seir.take_step(disease, a, map);
    }
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
