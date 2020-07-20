/*** main.cpp start ***/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "functions.h"

int main(){
	// time dependend seed
	srand(time(NULL));

	unsigned int n = 100;


	double r = random_walk_distance(n);

	std::cout << r << '\n';

	return 0;
}


/*** main.cpp end ***/
