/*
 *  @filename       main.cpp
 *  @tile           main
 *  @author         Team Infection
 *
 */
#include <iostream>
#include <array>

#include "Map.h"
#include "Disease.h"
#include "Model.h"

using std::cout;
using std::endl;

int main(int argc, char **argv) {

    //Declare a new model
    Model m_sir("SIR");

    /*
       std::vector<std::shared_ptr<Compartment>> model;
       model.push_back(std::shared_ptr<Compartment>(new S))
       model.push_back(std::shared_ptr<Compartment>(new I))
       model.push_back(std::shared_ptr<Compartment>(new R))

       Model m_custom("SIR", model);
    */

    int pop_width = 50;
    int pop_height = 50;
    int time = 500;
    int num_seeds = 1;

    //initialize disease
    Disease disease("sir_small range", 3, 20, 10);

    Map map(pop_width, pop_height);

    map.random_seed(disease, num_seeds);

    map.print_map();

    map = m_sir.take_step(disease, map, 50);

    map.print_map();

    return 0;
}
