#include "disease.h"

//In Disease class, implement the Disease ctor
  Disease::Disease(std::string n, double a, double b){

    name = n;
    alpha = a; //average infectious period (aka 1/alpha)
    beta = b; //contact rate

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

/*
int main(){
    Disease Zika("Zika", 1, 1);
    Zika.setBeta(5);
    std::cout  << Zika.getBeta() << std::endl;
    return 0;
}*/
