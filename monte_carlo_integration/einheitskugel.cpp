/*** einheitskugel.cpp start ***/

#include <iostream>
#include <time.h>
#include <random>
#include <cmath>


// function returning the distance from origin 
double distance(double x, double y, double z)
{
	return x*x + y*y + z*z;
}

int main()
{
	// random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0.0, 1.0);

	// Parameters
	unsigned int N = pow(10,9); // how many evalutations

	// coordinates
	double x = 0, y = 0, z = 0, r = 0;

	// counter for how many have been inside the sphere
	unsigned int n = 0;

	for (int i = 0; i < N; ++i)
	{
		// setting new coordinates and distance
		x = dis(gen);
		y = dis(gen);
		z = dis(gen);
		r = distance(x,y,z);

		// checking if point is inside the sphere
		if (r <= 1) ++n;
		//std::cout << r << '\t';
		//if (i % 3 == 0) std::cout << '\n';
	}

	/* calculating the probability of a evalutation laying inside the sphere
	 * based on V_cube = 2^3 = 8 and p calculating the Volume of the sphere, 
	 * based on V_sphere calculating pi */

	double p = n /(double)N;
	double V_sphere = p * 8;
	double my_pi = V_sphere * 3 / 4;

	std::cout << "Calculation based on ";
	std::cout << N << " evalutations.\n";

	std::cout << "Result for pi:\t" << my_pi << '\n';

	return 0;
}


/*** einheitskugel.cpp end ***/
