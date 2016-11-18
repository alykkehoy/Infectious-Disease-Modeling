#pragma once

#include "../disease.h"
#include "../map.h"
#include "State.h"

class I : public State {
public:
	I();
	~I();

	void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map);

private:
};