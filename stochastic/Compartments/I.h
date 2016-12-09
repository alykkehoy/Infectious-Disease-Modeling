#ifndef GUARD_I_H
#define GUARD_I_H

#include "../disease.h"
#include "../map.h"
#include "Compartment.h"

class I : public Compartment {
public:
	I();
	~I();

	void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map);

private:
};

#endif