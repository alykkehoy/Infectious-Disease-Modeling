#ifndef GUARD_E_H
#define GUARD_E_H

#include "../Disease.h"
#include "../Map.h"
#include "Compartment.h"

class E : public Compartment {
public:
	E();
	~E();

	void take_step(int i, int j, Disease& disease, Map& current_map);

private:
};

#endif
