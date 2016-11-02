#include <vector>
#include <iostream>

#include "analytics.h"

analytics::analytics(std::string output_file, int population_size, int seeds)
{
	file_name = output_file;
	pop_size = population_size;
	num_seeds = seeds;
}

analytics::~analytics()
{
}

int analytics::get_pop_size() {
	return pop_size;
}
void analytics::set_pop_size(int i) {
	pop_size = i;
}

std::vector<int> analytics::get_delta_i() {
	return delta_i;
}

std::vector<int> analytics::get_delta_s() {
	return delta_s;
}

std::vector<int> analytics::get_delta_r() {
	return delta_r;
}

//int analytics::get_delta_i_val(int i) {
//	return delta_i[i];
//}
//
//int analytics::get_delta_s_val(int i) {
//	return delta_s[i];
//}
//
//int analytics::get_delta_r_val(int i) {
//	return delta_r[i];
//}

void analytics::add_to_delta_i(int i) {
	delta_i.push_back(i);
}
void analytics::add_to_delta_s(int i) {
	delta_s.push_back(i);

}
void analytics::add_to_delta_r(int i) {
	delta_r.push_back(i);
}

void analytics::print_delta_analytics() {
	std::cout << "Time | Delta_S | Delta_I | Delta_R" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	for (int i = 0; i < delta_i.size(); i++) {
		std::cout << i + 1 << " | " << delta_s[i] << " | " << delta_i[i] << " | " << delta_r[i] << std::endl;
	}
}

void analytics::print_num_analytics() {
	create_num_s();
	create_num_i();
	create_num_r();
	std::cout << "Time  |  Num_S  |  Num_I  |  Num_R" << std::endl;
	std::cout << "----------------------------------" << std::endl;
	for (int i = 0; i < delta_i.size(); i++) {
		std::cout << i << " | " << num_s[i] << " | " << num_i[i] << " | " << num_r[i] << std::endl;
	}
}

void analytics::print_avg() {
	int sum_num_s = 0;
	int sum_num_i = 0;
	int sum_num_r = 0;

	int sum_delta_s = 0;
	int sum_delta_i = 0;
	int sum_delta_r = 0;

	if (num_i.size() == 0) {
		create_num_s();
		create_num_i();
		create_num_r();
	}
	for (int i = 0; i < num_i.size(); i++) {
		sum_num_s += num_s[i];
		sum_num_i += num_i[i];
		sum_num_r += num_r[i];
	}

	for (int i = 0; i < delta_i.size(); i++) {
		sum_delta_s += delta_s[i];
		sum_delta_i += delta_i[i];
		sum_delta_r += delta_r[i];
	}

	std::cout << "Avg num s = " << (double)sum_num_s / num_s.size() << std::endl;
	std::cout << "Avg num i = " << (double)sum_num_i / num_i.size() << std::endl;
	std::cout << "Avg num r = " << (double)sum_num_r / num_r.size() << std::endl;

	std::cout << "Avg delta s = " << (double)sum_delta_s / (double)delta_s.size() << std::endl;
	std::cout << "Avg delta i = " << (double)sum_delta_i / (double)delta_i.size() << std::endl;
	std::cout << "Avg delta r = " << (double)sum_delta_r / (double)delta_r.size() << std::endl;

	std::cout << "Avg number infected by a person: " << avg_num_infected << std::endl;
}


void analytics::create_num_s() {
	num_s.push_back(pop_size - num_seeds);
	for (int i = 0; i < delta_s.size(); i++) {
		num_s.push_back(num_s[i] + delta_s[i]);
	}
}

void analytics::create_num_i() {
	num_i.push_back(num_seeds);
	for (int i = 0; i < delta_i.size(); i++) {
		num_i.push_back(num_i[i] + delta_i[i]);
	}
}

void analytics::create_num_r() {
	num_r.push_back(0);
	for (int i = 0; i < delta_r.size(); i++) {
		num_r.push_back(num_r[i] + delta_r[i]);
	}
}

int analytics::get_num_seeds() {
	return num_seeds;
}

void analytics::set_num_seeds(int i) {
	num_seeds = i;
}

void analytics::create_avg_num_infected(Map& map) {
	avg_num_infected = 0;
	for (int i = 0; i < map.get_cols(); i++) {
		for (int j = 0; j < map.get_rows(); j++) {
			avg_num_infected += map.get_num_infected(j, i);
		}
	}
	avg_num_infected /= pop_size;
}
