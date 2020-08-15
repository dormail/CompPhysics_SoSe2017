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

void test(unsigned int const N, unsigned int const n, double &ref)
{
	++ref;
	std::cout << "test\n";
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
	// N anzahl an tests
	unsigned int n = 10;
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

	/* 2 threads simultanious */
	N /= 2; // nur halb so gros weil ja zwei threads arbeiten
	double data1, data2;
	std::thread t1(run, N, n, std::ref(data1));
	std::thread t2(run, N, n, std::ref(data2));
	
	t1.join();
	t2.join();
	
	double ave = data1 + data2;

	// double ave = sqrt(take_average(N,n));
	std::cout << ave << '\n';

	return 0;
}


/*** main.cpp end ***/
