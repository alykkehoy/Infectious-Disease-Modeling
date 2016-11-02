#pragma once
#include <vector>
#include <string>

#include "map.h"

class analytics
{
public:
	analytics(std::string output_file, int population_size, int seeds);
	~analytics();
	void calc_analytics(Map& map);

	void set_pop_size(int i);
	void set_num_seeds(int i);

	int get_num_seeds();
	int get_pop_size();
	std::vector<int> get_delta_i();
	std::vector<int> get_delta_s();
	std::vector<int> get_delta_r();

	void add_to_delta_i(int i);
	void add_to_delta_s(int i);
	void add_to_delta_r(int i);

	void print_delta_analytics();
	void print_num_analytics();
	void print_avg();

private:
	std::string file_name;

	int pop_size;
	int num_seeds;
	double avg_num_infected;

	std::vector<int> delta_i;
	std::vector<int> delta_s;
	std::vector<int> delta_r;

	std::vector<int> num_i;
	std::vector<int> num_s;
	std::vector<int> num_r;

	void create_num_s();
	void create_num_i();
	void create_num_r();
	void create_avg_num_infected(Map& map);
};

