/*** main.cpp start ***/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "functions.h"
#include <cmath>
#include <string>

int main(int argc, char** argv){
	if (argv[1] == "-h" || argv[1] == "help"){
		help();
		return 0;
	}

	// time dependend seed
	srand(time(NULL));

	// n reichweite des walks
	// N anzahl an tests
	unsigned int n = 60;
	unsigned int N = 10000;

	// liest input argument
	if (argc == 2){
		n = std::stoi(argv[1]);
	}
	if (argc == 3){
		n = std::stoi(argv[1]);
		N = std::stoi(argv[2]);
	}

	//double r = random_walk_distance(n);
	//std::cout << r << '\n';

	clock_t t = clock();
	double ave = sqrt(take_average(N,n));
	t = clock() - t;
	std::cout << ave << '\n';

	std::cout << "Random walk simulation of "
		<< N << " walks with range = "
		<< n << " took " << ((float)t) / CLOCKS_PER_SEC
		<< " seconds.\n";

	return 0;
}


/*** main.cpp end ***/
