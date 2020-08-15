/*** einheitskugel.cpp start ***/

#include <iostream>
#include <time.h>
#include <random>
#include <cmath> // mathematische funktionen
#include <thread>

// randomizer global
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0.0, 1.0);

// function returning the distance from origin 
double distance(double x, double y, double z){
	return x*x + y*y + z*z;
	//return sqrt(x*x + y*y + z*z); da radiu = 1 ist egal ob wurzel oder nicht
}

bool sim1()
	/* simulates one point
	 * true when inside
	 * false when outside
	 */
{
	double x = dis(gen),y = dis(gen), z = dis(gen);
	if (sqrt(x*x + y*y + z*z) >= 1) return false;
	else return true;
}

double simn(unsigned int const n) 
{
	double res = 0;
	for(unsigned int i = 0; i < n; ++i) 
	{
		if(sim1()) res += 1;
	}
	// res /= n;
	return res;
}

double res1, res2;

/* simn(1000); */
void simK1()
{
	res1 = simn(1000);
}
void simK2()
{
	res2 = simn(1000);
}

int main(int argc, char* argv[])
{
	double res1, res2;
	std::thread t1(simK1);
	std::thread t2(simK2);

	t1.join();
	t2.join();

	std::cout << "res1 = " << res1 << '\n';
	std::cout << "res2 = " << res2 << '\n';
	std::cout << "res1 + res2 = " << res1 + res2 << '\n';

	return 0;
}



#if 0
   int main()
   {
// Parameters
unsigned int N = pow(10,9); // how many evalutations

// coordinates
double x = 0, y = 0, z = 0, r = 0;

// counter for how many have been inside the sphere
unsigned int n = 0;

for (int i = 0; i < N; ++i){
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

// calculating the probability of a evalutation laying inside the sphere
// based on V_cube = 2^3 = 8 and p calculating the Volume of the sphere, 
// based on V_sphere calculating pi

double p = n /(double)N;
double V_sphere = p * 8;
double my_pi = V_sphere * 3 / 4;

std::cout << "Calculation based on ";
std::cout << N << " evalutations.\n";

std::cout << "Result for pi:\t" << my_pi << '\n';

return 0;
} 
#endif

/*** einheitskugel.cpp end ***/
