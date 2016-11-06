#pragma once

#include "../disease.h"
#include "../map.h"
#include "State.h"

class S: public State{
public:
	S();
	~S();

	void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map);

private:
};