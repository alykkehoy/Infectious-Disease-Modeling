
#include "disease.h"

//In Disease class, implement the Disease ctor
Disease::Disease(std::string n, double a, double b){

    name = n;
    alpha = a;
    beta = b;

}

double Disease::getAlpha(){

    return alpha;

}

double Disease::getBeta(){

    return beta;

}

std::string Disease::getName(){

    return name;

}

double Disease::setAlpha(double a){

    alpha = a;

}

double Disease::setBeta(double b){

    beta = b;

}

std::string Disease::setName(std::string n){

    name = n;

}

int main(){
    Disease Zika("Zika", 1, 1);
    Zika.setBeta(5);
    std::cout  << Zika.getBeta() << std::endl;
    return 0;
}
