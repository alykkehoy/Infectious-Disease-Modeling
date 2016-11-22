#pragma once
#include <vector>
#include <memory>

#include "States\State.h"
#include "States\S.h"
#include "States\E.h"
#include "States\I.h"
#include "States\R.h"

class Model
{
public:
	Model(std::string name, std::vector<std::shared_ptr<State>> model);
	~Model();

	Map take_step(Disease& disease, Map& current_map);

	std::string get_name();

private:

	std::string m_name;
	std::vector<std::shared_ptr<State>> m_model;
};
