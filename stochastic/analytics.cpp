#include "analytics.h"
#include <vector>
#include <iostream>


Analytics::Analytics()
{
}


Analytics::~Analytics()
{
}

int Analytics::get_pop_size() {
	return pop_size;
}
void Analytics::set_pop_size(int i) {
	pop_size = i;
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

int Analytics::get_delta_i_val(int i) {
	return delta_i[i];
}

int Analytics::get_delta_s_val(int i) {
	return delta_s[i];
}

int Analytics::get_delta_r_val(int i) {
	return delta_r[i];
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

void Analytics::print_delta_analytics() {
	std::cout << "Time | Delta_S | Delta_I | Delta_R" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	for (int i = 0; i < delta_i.size(); i++) {
		std::cout << i + 1 << " | " << delta_s[i] << " | " << delta_i[i] << " | " << delta_r[i] << std::endl;
	}
}

void Analytics::print_num_analytics() {
	create_num_s();
	create_num_i();
	create_num_r();
	std::cout << "Time  |  Num_S  |  Num_I  |  Num_R" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	for (int i = 0; i < delta_i.size(); i++) {
		std::cout << i << " | " << num_s[i] << " | " << num_i[i] << " | " << num_r[i] << std::endl;
	}
}

void Analytics::create_num_s() {
	num_s.push_back(pop_size - num_seeds);
	for (int i = 0; i < delta_s.size(); i++) {
		num_s.push_back(num_s[i] + delta_s[i]);
	}
}

void Analytics::create_num_i() {
	num_i.push_back(num_seeds);
	for (int i = 0; i < delta_i.size(); i++) {
		num_i.push_back(num_i[i] + delta_i[i]);
	}
}

void Analytics::create_num_r() {
	num_r.push_back(0);
	for (int i = 0; i < delta_r.size(); i++) {
		num_r.push_back(num_r[i] + delta_r[i]);
	}
}

int Analytics::get_num_seeds() {
	return num_seeds;
}

void Analytics::set_num_seeds(int i) {
	num_seeds = i;
}
