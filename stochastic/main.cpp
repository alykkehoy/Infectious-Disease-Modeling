/*

This file is a test run file for our disease libraries

*/

//include c++ libraries
#include <iostream>
#include <string>
#include <vector>
#include <memory>
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

	//stuff for testing custom models
	std::vector<std::shared_ptr<State>> model;
	model.push_back(std::shared_ptr<State>(new S));
	//model.push_back(std::shared_ptr<State>(new E));
	model.push_back(std::shared_ptr<State>(new I));
	model.push_back(std::shared_ptr<State>(new R));
	//model.push_back(std::shared_ptr<State>(new S));
	Model m_sir("SIR", model);

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

  for (int loops = 0; loops < time; loops++) {
	  std::cout << "Time: " << loops << std::endl;
	  map.print_map();
	 // map = m_sir.take_step(disease, map);

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
  return 0;
  }
}
