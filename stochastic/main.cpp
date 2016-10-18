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
	int rows = 10;
	int cols = 10;
	int time = 100;
  Map map(10, 10);
  Map nextMap = map;
  Disease disease("test", 10, 10);
  map.print_map();

  map.set_person_state(0, 0, 'I');
  
  for (int loops = 0; loops < time; loops++) {
	  for (int i = 0; i < rows; i++) {
		  for (int j = 0; j < cols; j++) {
			  if (map.population[i][j].getState() == 'S') {
				  for (int k = 0; k < map.number_of_adjacent_inffected(i, j, 1); k++) {
					  if (rand() % 100 <= disease.getBeta()) {
						  nextMap.set_person_state(i, j, 'I');
						  nextMap.set_person_infection_time(i, j, disease.getAlpha());
					  }
				  }
			  }
			  if (map.population[i][j].getState() == 'I') {
				  if (map.population[i][j].get_infection_time() == 0) {
					  nextMap.set_person_state(i, j, 'R');
				  }
				  else {
					  nextMap.set_person_infection_time(i, j, map.population[i][j].getState() - 1);
				  }
			  }
		  }
	  }
	  map = nextMap;
  }
  map.print_map();
  //create engine loop that calls the methods of the other files
  
    //print out visual representation of the program 
  
  return 0;
}
