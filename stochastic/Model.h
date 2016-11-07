#pragma once
#include <vector>

#include "States/State.h"
#include "States/S.h"
#include "States/I.h"
#include "States/R.h"

class Model
{
public:
	Model(std::string name, std::vector<State*> model);
	~Model();

	Map take_step(Disease& disease, Map& current_map);

	std::string get_name();

private:
	std::string m_name;
	std::vector<State*> m_model;
};
