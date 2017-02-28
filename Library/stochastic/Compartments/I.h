#ifndef GUARD_I_H
#define GUARD_I_H

#include "../Disease.h"
#include "../Map.h"
#include "Compartment.h"

class I : public Compartment {
public:
	I();
	~I();

	void take_step(int i, int j, Disease& disease, Map& current_map);

private:
};

#endif
