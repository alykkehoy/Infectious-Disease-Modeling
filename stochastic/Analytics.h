#pragma once
#include <vector>
class Analytics
{
public:
	Analytics();
	~Analytics();
	std::vector<int> get_delta_i();
	std::vector<int> get_delta_s();
	std::vector<int> get_delta_r();
	int get_detla_i_val(int i);
	int get_detla_s_val(int i);
	int get_detla_r_val(int i);
	void add_to_delta_i(int i);
	void add_to_delta_s(int i);
	void add_to_delta_r(int i);
	void print_analytics();

private:
	std::vector<int> delta_i;
	std::vector<int> delta_s;
	std::vector<int> delta_r;
};

