#ifndef GUARD_MAP_H
#define GUARD_MAP_H
#include "person.h"
#include "disease.h"
#include "analytics.h"
#include "map.h"

class SIR {
public:
	SIR();
	~SIR();
	Map take_step(Disease& disease);
	Map take_step(Disease& disease, analytics& a);
	int take_step_s(int i, int j, Disease& disease, Map& nextMap);
	int take_step_i(int i, int j, Map& nextMap);
	int take_step_r(int i, int j, Map& nextMap);
};
#endif