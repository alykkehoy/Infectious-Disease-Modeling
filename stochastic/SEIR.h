#pragma once
#include "map.h"

class SEIR
{
public:
	SEIR();
	~SEIR();
	Map take_step(Disease& disease, analytics& a, Map& current_map);
};

