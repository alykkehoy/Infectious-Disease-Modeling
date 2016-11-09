#include <vector>
#include "Model.h"

Model::Model(std::string name, std::vector<std::shared_ptr<State>> model)
{
	m_name = name;
	m_model = model;
}

Model::~Model()
{
}

std::string Model::get_name() {
	return m_name;
}

Map Model::take_step(Disease& disease, Map& current_map) {
	int rows = current_map.get_rows();
	int cols = current_map.get_cols();

	Map nextMap(cols, rows);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			nextMap.increment_num_infected(i, j, current_map.get_num_infected(i, j));
			nextMap.set_immune(i, j, current_map.get_immune(i, j));
			for(int k = 0; k < m_model.size(); k++){
				if (m_model[k]->get_char_rep() == current_map.get_person_state(i, j)) {
					m_model[k]->take_step(i, j, disease, nextMap, current_map, m_model);
					break;
				}
			}
		}
	}
	return nextMap;
}