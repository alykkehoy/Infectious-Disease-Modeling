/*
 *  @filename       _
 *  @fileheader     _
 *  @tile           _
 *  @author         Team Infection
 *
 */
#include <iostream>
#include <array> 
#include <boost/numeric/odeint.hpp> 
#include <functional> 
#include <iomanip>

using namespace std;
using namespace boost::numeric::odeint;
using namespace std::placeholders;
using state_type = array<double, 3>;

void diff(double
          const, double
          const, double
          const, state_type
          const &, state_type &, double
          const);

void write_diff(state_type
                const &, double
                const);

// Solving the differential equations for SIRS Model
void diff(double
          const beta, double
          const alpha, double
          const gamma,
          state_type
          const &x, state_type &dxdt,
          double
          const t) {
    dxdt[0] = -beta * x[0] * x[1] + gamma * x[2];
    dxdt[1] = beta * x[0] * x[1] - alpha * x[1];
    dxdt[2] = alpha * x[1] - gamma * x[2];
}

int main() {
    //Here gamma denotes the rate at which people leave the infected class
    double S0, I0, R0, alpha, beta, gamma, t0, t1, dt;

    //User defined values are taken for S,I,R,alpha,gamma,t0,t1 and dt
    cout << "Enter values for S,I,R,alpha,beta,gamma,t0,t1,dt" << endl;
    cin >> S0 >> I0 >> R0 >> alpha >> beta >> gamma >> t0 >> t1 >> dt;

    double N = S0 + I0 + R0;

    cout << '\n' << "Output of SIRS DETERMINISTIC Model" << '\n' << endl;
    cout << "The total population is " << N << '\n' << endl;

    //Displays the suceptible,infected and recovered number at each point of time.
    cout << "TIME" << '\t' << '\t' << "S(t)" << '\t' << "  I(t)" << '\t' << '\t' << "R(t)" << '\n' << endl;

    state_type x;
    x[0] = S0 / N;
    x[1] = I0 / N;
    x[2] = R0 / N;
    integrate(bind(diff, alpha, beta, gamma, _1, _2, _3),
              x, t0, t1, dt, write_diff);
}

void write_diff(const state_type &x,
                const double t) {
    cout.precision(5);
    cout.fill(' ');
    cout << setw(7) << t << ' ' << setw(12) << x[0] << ' ' << setw(12) << x[1] << ' ' << setw(12) << x[2] << endl;
}