#pragma once
#include <vector>
class analytics
{
public:
	analytics();
	~analytics();
	int get_pop_size();
	void set_pop_size(int i);
	int get_num_seeds();
	void set_num_seeds(int i);
	std::vector<int> get_delta_i();
	std::vector<int> get_delta_s();
	std::vector<int> get_delta_r();
	int get_delta_i_val(int i);
	int get_delta_s_val(int i);
	int get_delta_r_val(int i);
	void add_to_delta_i(int i);
	void add_to_delta_s(int i);
	void add_to_delta_r(int i);
	void print_delta_analytics();
	void print_num_analytics();
	void create_num_s();
	void create_num_i();
	void create_num_r();

private:
	int pop_size;
	int num_seeds;
	std::vector<int> delta_i;
	std::vector<int> delta_s;
	std::vector<int> delta_r;

	std::vector<int> num_i;
	std::vector<int> num_s;
	std::vector<int> num_r;
};

