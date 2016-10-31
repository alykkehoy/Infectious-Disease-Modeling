#ifndef GUARD_DISEASE_H
#define GUARD_DISEASE_H

#include <iostream>

class Disease
{
public:
    Disease(std::string n, double a, double b, double m_r, int r);
	Disease(std::string n, double a, double b, double m_r);
    std::string getName();
    double getAlpha();
    double getBeta();
	double get_mortality_rate();
	int get_range();

private:
	std::string name;
	double alpha;
	double beta;
	double mortality_rate;
	int range;
};


#endif // GUARD_DISEASE_H

