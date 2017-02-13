#ifndef GUARD_STATE_H
#define GUARD_STATE_H

//#include "../Person.h"
# include <memory> 
#include <vector>

#include "../Disease.h"
#include "../Map.h"

class Compartment {
    protected:
    char next_char;
    char char_representation;
    public:
    Compartment();
    ~Compartment();

    virtual void take_step(int i, int j, Disease & disease, Map & nextMap, Map & current_map) = 0;

    char get_char_rep();
    void create_next_char(std::vector < std::shared_ptr < Compartment >> model);

    void set_char_rep(char c);
    private:
};

#endif