#include<iostream>
#include<cmath>
#include "SIR.h"

using namespace std;

int main(int argc, char** argv)
{

	double beta0 = 1.5;
	double gamma0 =0.2;
	double I00 = 5;
	double S00 = 45;
	double tmax0 = 5;
	double step0=0.01/((beta0+gamma0)*S00);

	SIR testSIR(beta0,gamma0,step0,S00,I00,tmax0);
	testSIR.output();
	
	return(0);

}
