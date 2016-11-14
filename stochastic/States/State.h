#pragma once
//#include "../person.h"
#include <memory>
#include <vector>

#include "../disease.h"
#include "../analytics.h"
#include "../map.h"

class State {
protected:
	char next_char;
	char char_representation;
public:
	State();
	~State();

	virtual void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map) = 0;

	char get_char_rep();
	void create_next_char(std::vector<std::shared_ptr<State>> model);

	void set_char_rep(char c);
private:
};