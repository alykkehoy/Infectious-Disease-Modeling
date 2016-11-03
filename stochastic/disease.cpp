#include "disease.h"

//In Disease class, implement the Disease ctor
Disease::Disease(std::string n, double a, double b, double m_r, int r, int time) {
	range = r;
	name = n;
	alpha = a; //average infectious period (aka 1/alpha)
	beta = b; //contact rate
	mortality_rate = m_r;
	incubation_time = time;
}

Disease::Disease(std::string n, double a, double b, double m_r, int r) {
	range = r;
	name = n;
	alpha = a; //average infectious period (aka 1/alpha)
	beta = b; //contact rate
	mortality_rate = m_r;
	incubation_time = 0;
}

Disease::Disease(std::string n, double a, double b, double m_r) {
	//Disease(n, a, b, m_r, 1);
	range = 1;
	name = n;
	alpha = a; //average infectious period (aka 1/alpha)
	beta = b; //contact rate
	mortality_rate = m_r;
	incubation_time = 0;
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

int Disease::get_incubation_time() {
	return incubation_time;
}

void Disease::set_alpha(double a) {
	alpha = a;
}

void Disease::set_beta(double b) {
	beta = b;
}

void Disease::set_mortality_rate(double m_r) {
	mortality_rate = m_r;
}

void Disease::set_range(int r) {
	range = r;
}

void Disease::set_incubation_time(int t) {
	incubation_time = t;
}
