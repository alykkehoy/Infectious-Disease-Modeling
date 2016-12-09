#ifndef GUARD_R_H
#define GUARD_R_H

#include "../disease.h"
#include "../map.h"
#include "Compartment.h"

class R : public Compartment {
public:
	R();
	~R();

	void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map);

private:
};

#endif