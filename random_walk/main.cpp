/*** main.cpp start ***/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "functions.h"
#include <cmath>
#include <string>
#include <thread>

void run(unsigned int const N, unsigned int const n, double &data)
{
	data = sqrt(take_average(N,n));
}

int main(int argc, char** argv)
{
	if (argv[1] == "-h" || argv[1] == "help"){
		help();
		return 0;
	}

	// time dependend seed
	srand(time(NULL));

	// n reichweite des walks
	// N anzahl an tests pro thread
	unsigned int n = 60;
	unsigned int N = 5000;

	// liest input argument
	if (argc == 2){
		n = std::stoi(argv[1]);
	}
	if (argc == 3){
		n = std::stoi(argv[1]);
		N = std::stoi(argv[2]);
	}

	/* 2 threads simultanious */
	clock_t t = clock();
	double data1, data2;
	std::thread t1(run, N, n, std::ref(data1));
	std::thread t2(run, N, n, std::ref(data2));
	
	t1.join();
	t2.join();
	
	double ave = data1 + data2;
	t = clock() - t;

	// double ave = sqrt(take_average(N,n));
	std::cout << ave << '\n';
	std::cout << "Random walk simulation in 2 treads took "
		<< ((float)t) / CLOCKS_PER_SEC
		<< " seconds.\n";


	return 0;
}


/*** main.cpp end ***/
