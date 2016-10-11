#ifndef GUARD_DISEASE
#define GUARD_DISEASE

#include <iostream>

class Disease
{
    std::string name;
    double alpha;
    double beta;

public:
    Disease(std::string n, double a, double b);

    std::string getName();
    double getAlpha();
    double getBeta();

    std::string setName(std::string n);
    double setAlpha(double a);
    double setBeta(double b);


};



#endif // GUARD_DISEASE


