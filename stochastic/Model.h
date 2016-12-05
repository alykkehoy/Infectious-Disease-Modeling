#ifndef GUARD_MODEL_H
#define GUARD_MODEL_H

#include <vector>
#include <memory>
#include <fstream>

#include "States/State.h"
#include "States/S.h"
#include "States/E.h"
#include "States/I.h"
#include "States/R.h"

class Model
{
public:
	Model(std::string name, std::vector<std::shared_ptr<State>> model);
	Model(std::string name);
	~Model();

	void init_counters(Map &map);
	void print_counters();
	void export_counters(std::string file_name);
	Map take_step(Disease& disease, Map& current_map);
	Map take_step(Disease& disease, Map& current_map, int steps);

	std::string get_name();

private:
	void take_count(Map &map);

	bool counters_on = false;
	std::string m_name;
	std::vector<std::shared_ptr<State>> m_model;
	std::vector<std::vector<int>> m_counters;
};

#endif