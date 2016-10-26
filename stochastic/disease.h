#ifndef GUARD_DISEASE_H
#define GUARD_DISEASE_H

#include <iostream>

class Disease
{
private:
    std::string name;
    double alpha;
    double beta;
	int range;

public:
    Disease(std::string n, double a, double b, int r);
	Disease(std::string n, double a, double b);
    std::string getName();
    double getAlpha();
    double getBeta();
	int get_range();

};


#endif // GUARD_DISEASE_H

