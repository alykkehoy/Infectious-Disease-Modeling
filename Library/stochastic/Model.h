/*
 *  @filename       Model.h
 *  @tile           Model
 *  @author         Team Infection
 *
 */
#ifndef GUARD_MODEL_H
#define GUARD_MODEL_H

#include <vector>
#include <memory>
#include <fstream>
#include <string>

#include "Compartments/Compartment.h"
#include "Compartments/S.h"
#include "Compartments/E.h"
#include "Compartments/I.h"
#include "Compartments/R.h"

class Model {
public:
    Model(std::string name, std::vector <std::shared_ptr<Compartment>> model);

    Model(std::string name);

    ~Model();

    void init_counters(Map &map);

    void print_counters();

    void export_counters(std::string file_name);

    void take_step(Disease &disease, Map &current_map);

    void take_step(Disease &disease, Map &current_map, int steps);

    std::string get_name();

private:
    void take_count(Map &map);

    bool counters_on = false;
    std::string m_name;
    std::vector <std::shared_ptr<Compartment >> m_model;
    std::vector <std::vector<int >> m_counters;
};

#endif
