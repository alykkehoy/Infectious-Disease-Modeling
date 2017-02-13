/*
 *  @filename       base.h_
 *  @tile           Deterministiceterministic base class
 *  @author         Team Infection
 *
 */

#pragma once 
#include <iostream>
#include <array> 
#include <boost/numeric/odeint.hpp> 
#include <functional> 
#include <iomanip>

using namespace std;
using namespace boost::numeric::odeint;
using namespace std::placeholders;
using state_type = array<double, 3>;
using alpha_beta_gama = array<double, 3>;

	void diff(alpha_beta_gama const, state_type
          const &, state_type &, double
          const);

	void write_diff(state_type
                const &, double
                const);
					
#pragma once