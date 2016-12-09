#ifndef GUARD_E_H
#define GUARD_E_H

#include "../disease.h"
#include "../map.h"
#include "Compartment.h"

class E : public Compartment {
public:
	E();
	~E();

	void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map);

private:
};

#endif