#include "Analytics.h"
#include <vector>
#include <iostream>


Analytics::Analytics()
{
}


Analytics::~Analytics()
{
}

std::vector<int> Analytics::get_delta_i() {
	return delta_i;
}

std::vector<int> Analytics::get_delta_s() {
	return delta_s;
}

std::vector<int> Analytics::get_delta_r() {
	return delta_r;
}

void Analytics::add_to_delta_i(int i) {
	delta_i.push_back(i);
}
void Analytics::add_to_delta_s(int i) {
	delta_s.push_back(i);

}
void Analytics::add_to_delta_r(int i) {
	delta_r.push_back(i);
}

void Analytics::print_analytics() {
	std::cout << "Time | Delta_I | Delta_S | Delta_R" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	for (int i = 0; i < delta_i.size() || i < delta_s.size() || i < delta_r.size(); i++) {
		std::cout << i << " | " << delta_i[i] << " | " << delta_s[i] << " | " << delta_r[i] << std::endl;
	}
}
