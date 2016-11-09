#pragma once
//#include "../person.h"
#include <memory>
#include <vector>

#include "../disease.h"
#include "../analytics.h"
#include "../map.h"

class State {
protected:
	char char_representation;
public:
	State();
	~State();

	virtual void take_step(int i, int j, Disease& disease, Map& nextMap, Map& current_map, std::vector<std::shared_ptr<State>> model) = 0;

	char get_char_rep();
	char get_next_char_rep(std::vector<std::shared_ptr<State>> model);

	void set_char_rep(char c);
private:
};