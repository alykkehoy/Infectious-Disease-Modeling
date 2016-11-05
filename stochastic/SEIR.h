#pragma once
#include "map.h"
#include "analytics.h"

class SEIR
{
public:
	SEIR();
	~SEIR();
	Map take_step(Disease& disease, analytics& a, Map& current_map);
private:
	int take_step_s(int y, int x, Disease& disease, Map& nextMap, Map& current_map);
	int take_step_e(int y, int x, Disease& disease, Map& nextMap, Map& current_map);
	int take_step_i(int i, int j, Map& nextMap, Map& current_map);
	int take_step_r(int i, int j, Disease& disease, Map& nextMap, Map& current_map);
};

