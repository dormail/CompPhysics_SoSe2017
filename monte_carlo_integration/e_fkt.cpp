/*** e_fkt.cpp start 
 * Berechnet das Integral 
 * \int_{-\inf}^{T_1} \frac{1}{\sqrt{pi}} \exp(-x^2) dx
 * numerische, einmal mit Monte Carlo und einmal mit Mittelpunktsregel
 * ***/

#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <new>


constexpr double e = 2.71828;
constexpr double pi = 3.1415927;

// funktion ueber die integriert wird
double f(double x){
	return 1 / pi * pow(e, -1 * x * x);
}

// implementieren sum. mittelpunktregel
double wert_mittel(double (*f)(double), double a, double b, double h){
	if(h == 0){
		std::cout << "Error: h=0\n";
		throw -1;
	}
	// Anzahl an Punkten zum Auswerten
	unsigned int const N_max = abs(b-a) / h;
	
	double sum = 0;
	for (unsigned int i = 1; i < N_max; i++){
		sum += h * f(a+h/2);
		a += h;
	}

	return sum;
}

double mittel(double (*f)(double), double a, double b, double h){
	// vergleicht fuer zwei werte von h
	double y_2 = wert_mittel(f,a,b,h);
	double y_1 = wert_mittel(f,a,b,h/2);

	if(abs(y_2 - y_1) < 0.000000001){
		return y_2;
	}
	else {
		return mittel(f,a,b,h/2);
	}
}

// implementierung monte carlo
double mc_integral(double (*f)(double), double a, double b, unsigned int  N){
	// random number generator
	// read more under
	// https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(a,b);

	double sum = 0;

	for (unsigned int i = 1; i < N; ++i){
		sum += f(dis(gen));
	}
	sum *= abs(b-a) /(double) N;

	return sum;
}

int main(){
	unsigned int  N = pow(10,9);
	double I_1 = 0, I_2 = 0, I_3 = 0;
	double I_1_mc = 0, I_2_mc = 0, I_3_mc = 0;

	double min = -100000;

	// Berechnung in Teilintervallen
	// -Inf wird durch -100000 ersetzt
	// -Inf bis -1 
	I_1 = mittel(f,-10,-1,0.001);
	I_1 += mittel(f,-100,-10,0.01);
	I_1 += mittel(f,-1000,-100,0.1);
	I_1 += mittel(f,-100000,-1000,1);

	// -Inf bis 1.1631
	I_2 = I_1 + mittel(f,-1,1.1613,0.0001);
	
	// -Inf bis Inf 
	I_3 = I_1 + mittel(f,-1,0,0.0001);
	I_3 *= 2;

	// Monte Carlo
	I_1_mc = mc_integral(f,min,-1,N);
	I_2_mc = I_1 + mc_integral(f,-1,1.1631,N / 10000); // zusammen gesetzt um rechenzeit zu sparen
	I_3_mc = 2 * mc_integral(f,min,0,N);

	std::cout << "Berechnung mit sum. Mittelpunkt\n";
	std::cout << "I_1 = " << I_1 << '\n';
	std::cout << "I_2 = " << I_2 << '\n';
	std::cout << "I_3 = " << I_3 << '\n';
	std::cout << "Berechnung mit Monte-Carlo Integration\n";
	std::cout << "I_1 = " << I_1_mc << '\n';
	std::cout << "I_2 = " << I_2_mc << '\n';
	std::cout << "I_3 = " << I_3_mc << '\n';

	return 0;
}

/*** e_fkt.cpp end ***/
