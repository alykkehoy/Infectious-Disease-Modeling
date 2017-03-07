/*
 *  @filename       Model.cpp
 *  @fileheader     Model.h
 *  @tile           Model
 *  @author         Team Infection
 *
 */

#include <vector>
#include "Model.h"


Model::Model(std::string name, std::vector <std::shared_ptr<Compartment>> model) : m_name(name), m_model(model) {
    for (int i = 0; i < model.size(); i++) {
        model[i]->create_next_char(model);
    }
    init_counters();
}

Model::Model(std::string name) : m_name(name) {
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 'S' || name[i] == 's') {
            std::cout << "S";
            m_model.push_back(std::shared_ptr<Compartment>(new S));
        } else if (name[i] == 'E' || name[i] == 'e') {
            std::cout << "E";
            m_model.push_back(std::shared_ptr<Compartment>(new E));
        } else if (name[i] == 'I' || name[i] == 'i') {
            std::cout << "I";
            m_model.push_back(std::shared_ptr<Compartment>(new I));
        } else if (name[i] == 'R' || name[i] == 'r') {
            std::cout << "R";
            m_model.push_back(std::shared_ptr<Compartment>(new R));
        }
    }
    std::cout << std::endl;
    for (int i = 0; i < name.size(); i++) {
        m_model[i]->create_next_char(m_model);
    }
    init_counters();
}

Model::~Model() {}

void Model::init_counters() {
    for (int i = 0; i < m_model.size(); i++) {
        std::vector<int> counter;
        m_counters.push_back(counter);
    }
    return;
}


void Model::print_counters() {
    for (int i = 0; i < m_counters[0].size(); i++) {
        for (int j = 0; j < m_counters.size(); j++) {
            std::cout << m_counters[j][i] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

void Model::export_counters(std::string file_name) {
    std::cout << "Export to " << file_name << ".csv started..." << std::endl;

    std::ofstream file;
    file.open(file_name + ".csv", std::ofstream::out);

    for (int i = 0; i < m_counters[0].size(); i++) {
        for (int j = 0; j < m_counters.size() - 1; j++) {
            file << m_counters[j][i] << ",";
        }
        file << m_counters[m_counters.size() - 1][i];
        file << '\n';
    }

    file.close();
    std::cout << "Export complete." << std::endl;
    return;
}

std::string Model::get_name() {
    return m_name;
}

void Model::take_step(Disease &disease, Map &current_map) {
    int rows = current_map.get_rows();
    int cols = current_map.get_cols();
    int counterSize = m_counters.size();

    for (int i = 0; i < counterSize; i++) {
        m_counters[i].push_back(0);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //nextMap.increment_num_infected(i, j, current_map.get_num_infected(i, j));
            //nextMap.set_immune(i, j, current_map.get_immune(i, j));
            int k = findCompartment(current_map.get_person_state(i, j));
            if(m_model[k]->take_step(i, j, disease, current_map) && k != m_model.size() - 1){
                m_counters[k + 1][m_counters[k].size() - 1]++;
            } else {
                m_counters[k][m_counters[k].size() - 1]++;
            }
        }
    }

    current_map.swap();
}

int Model::findCompartment(char state){
    for(int k = 0; k < m_model.size(); k++){
        if(m_model[k]->get_char_rep() == state){
            return k;
        }
    }
    return -1;
}

void Model::take_step(Disease &disease, Map &current_map, int steps) {
    for (int i = 0; i < steps; i++) {
        take_step(disease, current_map);
    }
}
