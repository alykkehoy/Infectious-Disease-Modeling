#ifndef GUARD_MAP_H
#define GUARD_MAP_H

#include "Person.h"
#include "Disease.h"
#include <random>

class Map {
	public:
	Map(int width, int height);
	Map(Map & original);
	~Map();
	Map & operator = (Map
		const & arg);

	void setEveryoneHealthy();
	void random_seed(Disease & disease);
	void random_seed(Disease & disease, int num_seeds);
	void random_seed_immunity(int percent);

	int get_rows() const;
	int get_cols() const;
	Person * * getGrid();
	char get_person_state(int i, int j) const;
	int get_person_infection_time(int i, int j) const;
	int get_num_infected(int i, int j) const;
	bool get_immune(int i, int j) const;
	int get_incubation_timer(int i, int j) const;

	void set_person_state(int i, int j, char state);
	void set_person_infection_time(int i, int j, int time);
	void set_num_infected(int i, int j, int num);
	void increment_num_infected(int i, int j);
	void increment_num_infected(int i, int j, int num);
	void set_immune(int i, int j, bool a);
	void set_incubation_timer(int i, int j, int time);

	void print_map();
	void print_num_infected_map();
	void print_immunity_map();
	void print_test_map();

	private:
		Person * * population;
	int rows;
	int cols;

};
	#endif // GUARD_MAP_H