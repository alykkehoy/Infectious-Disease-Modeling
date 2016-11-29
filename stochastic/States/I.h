#ifndef GUARD_I_H
#define GUARD_I_H

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

#endif