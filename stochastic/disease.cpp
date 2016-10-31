#include "disease.h"

//In Disease class, implement the Disease ctor
Disease::Disease(std::string n, double a, double b, double m_r, int r){
	range = r;
	name = n;
	alpha = a; //average infectious period (aka 1/alpha)
	beta = b; //contact rate
	mortality_rate = m_r;
}

Disease::Disease(std::string n, double a, double b, double m_r) {
	//Disease(n, a, b, m_r, 1);
	range = 1;
	name = n;
	alpha = a; //average infectious period (aka 1/alpha)
	beta = b; //contact rate
	mortality_rate = m_r;
}


double Disease::getAlpha(){
  return alpha;
}

double Disease::get_mortality_rate() {
	return mortality_rate;
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
