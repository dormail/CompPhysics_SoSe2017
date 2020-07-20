/*** random_walk_distance.cpp start ***/

#include "functions.h"
#include <tuple>
#include <cmath>
#include <iostream>

double random_walk_distance(unsigned int n){
	std::tuple<int, int> end_position (10, 10);
	bool repeat = true;
	while(repeat){
		//std::cout << "test\n";
		try{
			end_position = random_walk(n);
			repeat = false;
		}
		catch(int a){
		}
	}


	double r = std::get<0>(end_position) * std::get<0>(end_position);
	r += std::get<1>(end_position) * std::get<1>(end_position);
	// Da wir eh die quadratische cluster groesse wollen auskommentiert
	//r = sqrt(r);

	return r;
}

/*** random_walk_distance.cpp end ***/
