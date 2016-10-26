#include "disease.h"

//In Disease class, implement the Disease ctor
Disease::Disease(std::string n, double a, double b, int r){
	range = r;
	name = n;
	alpha = a; //average infectious period (aka 1/alpha)
	beta = b; //contact rate
}

Disease::Disease(std::string n, double a, double b) {
	range = 1;
	name = n;
	alpha = a; //average infectious period (aka 1/alpha)
	beta = b; //contact rate
}


double Disease::getAlpha(){
  return alpha;
}

double Disease::getBeta(){
  return beta;
}

int Disease::get_range() {
	return range;
}

std::string Disease::getName(){
  return name;
}
