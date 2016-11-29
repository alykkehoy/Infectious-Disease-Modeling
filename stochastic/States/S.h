#ifndef GUARD_S_H
#define GUARD_S_H

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

#endif