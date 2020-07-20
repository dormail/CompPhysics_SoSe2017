/*** take_average.cpp start
 * N Anzahl an Testlaufen
 * n Reichtweite des Walks
 * ***/

#include "functions.h"

double take_average(unsigned int const N, unsigned int const n){
	// time dependend seed
	// srand(time(NULL));

	double sum = 0;
	for (unsigned int i = 0; i < N; i++){
		sum += random_walk_distance(n) / N;
	}
	return sum;
}


/*** take_average.cpp end ***/
