/*

This file is a test run file for our disease libraries

*/

//include c++ libraries
#include <iostream>
#include <string>

//include all of the other files in the program
#include "neighborhood.h"
#include "person.h"
#include "map.h"
#include "disease.h"
#include "text_parse.h" //parse through simulation parameter text file

int main(){
  /*
  load simulation files (we'll do that later and set in this method now)
  */
  
  //new disease
  //Disease Zika("Zika", 1, 1); 

  Map map(10, 10);
  map.print_map();
  
  //create engine loop that calls the methods of the other files
  
    //print out visual representation of the program 
  
  return 0;
}
