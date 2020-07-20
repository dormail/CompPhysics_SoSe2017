/*** random_walk_distance.cpp start ***/

#include "functions.h"
#include <tuple>
#include <cmath>

double random_walk_distance(unsigned int n){
	std::tuple<int, int> end_position = random_walk(n);

	double r = std::get<0>(end_position) * std::get<0>(end_position);
	r += std::get<1>(end_position) * std::get<1>(end_position);
	r = sqrt(r);

	return r;
}

/*** random_walk_distance.cpp end ***/
