/*** main.cpp start ***/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "functions.h"
#include <cmath>
#include <string>

int main(int argc, char** argv){
	// time dependend seed
	srand(time(NULL));

	// n reichweite des walks
	// N anzahl an tests
	unsigned int n = 10;
	unsigned int N = 10000;

	// liest input argument
	if (argc > 1){
		n = std::stoi(argv[1]);
	}

	//double r = random_walk_distance(n);
	//std::cout << r << '\n';
	
	double ave = sqrt(take_average(N,n));
	std::cout << ave << '\n';

	return 0;
}


/*** main.cpp end ***/
