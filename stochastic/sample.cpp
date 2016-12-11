#include <iostream>
#include <array>

#include "Map.h"
#include "Disease.h"
#include "Model.h"

using std::cout;
using std::endl;

int main(int argc, char** argv){
	
	//Declare a new model
	Model m_sir("SIR");
	
	/*
	std::vector<std::shared_ptr<Compartment>> model;
	model.push_back(std::shared_ptr<Compartment>(new S));
	model.push_back(std::shared_ptr<Compartment>(new I));
	model.push_back(std::shared_ptr<Compartment>(new S));
	
	Model m_custom("SIR", model); //String name, vector of the model 
	*/
	
    //Initialize disease
	Disease disease("sir_small range", 3, 20, 10);

	//Initialize map
	Map map(50, 50);
	
	m_sir.init_counters(map);

	map.random_seed(disease, 1);
	
    map = m_sir.take_step(disease, map, 50);
	
	//Print the map
	map.print_map();
	
	return 0;
}
