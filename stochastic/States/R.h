#pragma once

#include "../disease.h"
#include "../map.h"
#include "State.h"

class R : public State {
public:
	R();
	~R();

	void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map, std::vector<std::shared_ptr<State>> model);

private:
};
