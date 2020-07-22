/*** random_walk_test.cpp start 
 * script testing the random walk for numbers between 5 and 60 and storing them in a file
 * ***/

#include <iostream>
#include <fstream>
#include <cmath>
#include "functions.h"

int main(){
	// variables
	unsigned int n_min = 5; // min amount of steps for the test
	unsigned int n_max = 60; // max amount of steps

	unsigned int N = 10000; // how many times should each amount be tested

	std::string filename = "random_walk_results.csv";

	std::cout << "Simulating random walks from " << n_min << " to " << n_max << ".\n";

	std::ofstream ofile;
	ofile.open(filename);

	// writing first line in the csv
	// n is amount of steps, r is the average distance at the end
	ofile << "n,r\n";

	for (unsigned int i = n_min; i <= 60; ++i){
		ofile << i << ',';
		ofile << sqrt(take_average(N,i)) << '\n';

		//std::cout << i << '\n';
	}

	std::cout << "Results written into " << filename << ".\n";

	ofile.close();

	return 0;
}


/*** random_walk_test.cpp end ***/
